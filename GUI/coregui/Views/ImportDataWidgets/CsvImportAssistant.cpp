// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/ImportDataWidgets/CsvImportAssistant.cpp
//! @brief     Implements class CsvImportAssistant
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "DataFormatUtils.cpp"
#include "CsvImportAssistant.h"
#include "mainwindow_constants.h"
#include "StyleUtils.h"
#include <QAction>
#include <QPushButton>
#include <QTableWidget>
#include <QSettings>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QMenu>

namespace
{
const QSize default_dialog_size(600, 800);
}

CsvImportAssistant::CsvImportAssistant(QString dir, QString file, QWidget* parent):
    QDialog(parent),
    m_dirName(dir),
    m_fileName(file),
    m_lastDataRow(0),
    m_tableWidget(nullptr),
    m_filePathField(nullptr),
    m_separatorField(nullptr),
    m_firstDataRowSpinBox(nullptr),
    m_singleDataColSpinBox(nullptr)
{
    setWindowTitle("Data Importer");
    setMinimumSize(128, 128);
    resize(600, 800);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    auto layout = new QVBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addLayout(createLayout());

    setLayout(layout);

    StyleUtils::setResizable(this);

    if(!m_fileName.isEmpty())
        CsvImportAssistant::Reload();
}



QBoxLayout* CsvImportAssistant::createLayout()
{
    auto result = new QVBoxLayout;
    auto preresult = new QHBoxLayout;

    auto importButton = new QPushButton("Import");
    connect(importButton, &QPushButton::clicked, this, &CsvImportAssistant::onImportButton);

    auto rejectButton = new QPushButton("Cancel");
    connect(rejectButton, &QPushButton::clicked, this, &CsvImportAssistant::onRejectButton);


    m_tableWidget = new QTableWidget();

    preresult->setMargin(10);

    preresult->addWidget(rejectButton);
    preresult->addWidget(importButton);


    result->setMargin(10);
    result->addWidget(m_tableWidget);

    result->addLayout(CsvImportAssistant::createFileDetailsLayout());


    result->addLayout(preresult);

    m_tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(m_tableWidget, &QTableWidget::cellClicked, this, &CsvImportAssistant::OnColumnClicked);
    connect(m_tableWidget, &QTableWidget::customContextMenuRequested, this, &CsvImportAssistant::onColumnRightClick);
    return result;
}

QBoxLayout* CsvImportAssistant::createFileDetailsLayout(){
    auto result = new QVBoxLayout;
    result->setMargin(10);

    auto labelFilepath = new QLabel("File to import: ");
    m_filePathField = new QLineEdit(m_fileName,this);
    auto browseButton = new QPushButton("browse");
    connect(browseButton, &QPushButton::clicked, this, &CsvImportAssistant::onBrowseButton);
    auto lay1 = new QHBoxLayout;
    lay1->addWidget(labelFilepath);
    lay1->addWidget(m_filePathField);
    lay1->addWidget(browseButton);

    result->addLayout(lay1);

    auto labelSeparator = new QLabel("Separator: ");
    m_separatorField = new QLineEdit(QString(guessSeparator()));
    m_separatorField->setMaxLength(1);
    auto lay2 = new QHBoxLayout;
    lay2->addWidget(labelSeparator);
    lay2->addWidget(m_separatorField);
    result->addLayout(lay2);
    connect(m_separatorField, &QLineEdit::editingFinished, this, &CsvImportAssistant::Reload);


    auto labelFirstDataRow = new QLabel("First data row: ");
    m_firstDataRowSpinBox = new QSpinBox();
    m_firstDataRowSpinBox->setMinimum(1);
    m_firstDataRowSpinBox->setMaximum(1);
    m_firstDataRowSpinBox->setValue(1);
    auto lay4 = new QHBoxLayout;
    lay4->addWidget(labelFirstDataRow);
    lay4->addWidget(m_firstDataRowSpinBox);
    result->addLayout(lay4);
    connect(m_firstDataRowSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &CsvImportAssistant::onIntChanged);

    auto labelSingleColImport = new QLabel("Import Single Column (zero to import all): ");
    m_singleDataColSpinBox = new QSpinBox();
    m_singleDataColSpinBox->setMinimum(0);
    m_singleDataColSpinBox->setMaximum(0);
    m_singleDataColSpinBox->setValue(0);
    auto laySingleDataCol = new QHBoxLayout;
    laySingleDataCol->addWidget(labelSingleColImport);
    laySingleDataCol->addWidget(m_singleDataColSpinBox);
    result->addLayout(laySingleDataCol);
    connect(m_singleDataColSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &CsvImportAssistant::onIntChanged);



    auto lay6 = new QVBoxLayout;
    auto reloadButton = new QPushButton("Reload");
    lay6->addWidget(reloadButton);
    reloadButton->setDefault(true);
    connect(reloadButton, &QPushButton::clicked, this, &CsvImportAssistant::onReloadButton);



    result->addLayout(lay1);
    result->addLayout(lay2);
    result->addLayout(lay4);
    result->addLayout(lay6);

    return result;
}

void CsvImportAssistant::onBrowseButton()
{
    const QString filter_string = "Intensity File (*.txt *.dat *.ascii *.int *.gz *.tif *.tiff *.csv);;All files (*.*)";
    QString fileName = QFileDialog::getOpenFileName(nullptr, QStringLiteral("Open Intensity File"),
                                                    this->m_dirName, filter_string);
    if(fileName != nullptr){
        m_filePathField->setText(fileName);
        m_fileName = fileName;
        CsvImportAssistant::Reload();
    }

}

void CsvImportAssistant::Reload()
{
    ifstream f(filepath().toStdString());
    if(f.good()){
        generate_table();
    }else{
        QMessageBox msgBox;
        string message = "There was a problem opening the file \"" + filepath().toStdString() + "\"";
        message += "\n Check for any errors in the path and try again.";
        msgBox.setText(QString::fromStdString(message));
        msgBox.setIcon(msgBox.Critical);
        msgBox.exec();
    }
}

void CsvImportAssistant::onRejectButton(){
    reject();
}


void CsvImportAssistant::onImportButton()
{
    try {
        auto data = getData();
        accept();
    } catch(exception& e){
        QString message = QString("Unable to import, check that the table contains only numerical values");
        QMessageBox::warning(nullptr, "Wrong data format", message);
    }
}


unique_ptr<OutputData<double>> CsvImportAssistant::getData()
{
    int nTableRows = m_tableWidget->rowCount();
    int nTableCols = m_tableWidget->columnCount();
    vector<vector<string>> StringVectorVector;
    vector<string> StringVector;

    //save the values of the array
    size_t nDataCols = 0;
    size_t nDataRows = 0;
    for(int i = 0; i < nTableRows; i++){
        StringVector.clear();
        nDataCols = 0;
        for(int j = 0; j < nTableCols; j++){
            auto tableElement = m_tableWidget->item(i,j);
            if(tableElement != nullptr){
                StringVector.push_back(tableElement->text().toStdString());
                nDataCols++;
            }
        }
        StringVectorVector.push_back(StringVector);
        nDataRows++;
    }

    unique_ptr<OutputData<double>> result;
    result.reset(new OutputData<double>());

    if( (nDataCols < 2) || (nDataRows < 2) ){
        size_t nElem = max(nDataCols,nDataRows);
        result->addAxis("intensity", nElem, 0.0, double(nElem));
        vector<unsigned> axes_indices(1);
        unsigned item = 0;
        for(unsigned row=0; row<nDataRows; row++) {
            for(unsigned col=0; col<nDataCols; col++) {
                axes_indices[0] = item;
                size_t global_index = result->toGlobalIndex(axes_indices);
                string string_to_parse;
                vector<double> parsed_doubles;
                string_to_parse = StringVectorVector[row][col];
                parsed_doubles = DataFormatUtils::parse_doubles(string_to_parse);
                (*result)[global_index] = parsed_doubles[0];
                item++;
            }
        }
    }
    else{
        result->addAxis("x", nDataCols, 0.0, double(nDataCols));
        result->addAxis("y", nDataRows, 0.0, double(nDataRows));
        vector<unsigned> axes_indices(2);
        for(unsigned row=0; row<nDataRows; row++) {
            for(unsigned col=0; col<nDataCols; col++) {
                axes_indices[0] = col;
                axes_indices[1] = static_cast<unsigned>(nDataRows) - 1 - row;
                size_t global_index = result->toGlobalIndex(axes_indices);
                string string_to_parse;
                vector<double> parsed_doubles;
                string_to_parse = StringVectorVector[row][col];
                parsed_doubles = DataFormatUtils::parse_doubles(string_to_parse);
                (*result)[global_index] = parsed_doubles[0];
            }
        }
    }
    return result;
}


void CsvImportAssistant::generate_table()
{
    unique_ptr<CSVFile> csvFile;
    try{
        csvFile.reset(new CSVFile(filepath().toStdString(), separator(), headersLine()));
    }
    catch(...){
        QMessageBox msgBox;
        string message = "There was a problem opening the file \"" + filepath().toStdString() + "\"";
        msgBox.setText(QString::fromStdString(message));
        msgBox.setIcon(msgBox.Critical);
        msgBox.exec();
        return;
    }

    m_tableWidget->clearContents();
    m_tableWidget->setColumnCount(int(csvFile->NumberOfColumns()));
    m_tableWidget->setRowCount(0);
    m_lastDataRow = unsigned(csvFile->NumberOfRows());
    m_firstDataRowSpinBox->setMaximum(int(csvFile->NumberOfRows()));
    m_singleDataColSpinBox->setMaximum(int(csvFile->NumberOfColumns()));

    set_table_data(csvFile->asArray());
    remove_unwanted();
    setRowNumbering();

    return;
}

void CsvImportAssistant::set_table_data(vector<vector<string>> dataArray){
    unsigned firstDataLine = firstLine() - 1;
    unsigned lastDataLine = lastLine();
    for(unsigned i = firstDataLine; i < lastDataLine; i++){
        m_tableWidget->insertRow(m_tableWidget->rowCount());
        unsigned I = unsigned(m_tableWidget->rowCount()) - 1;
        for(unsigned j = 0; j < dataArray[i].size(); j++){
            m_tableWidget->setItem(int(I),int(j),new QTableWidgetItem(QString::fromStdString(dataArray[i][j])));
        }
    }
}

void CsvImportAssistant::remove_unwanted(){
    int nRows = m_tableWidget->rowCount();
    int nCols = m_tableWidget->columnCount();
    vector<vector<string>> StringVectorVector;
    vector<string> StringVector;
    vector<int> to_be_removed;

    //save the inices of blank cols
    for(int j = 0; j < nCols; j++){

        if(singleColumnImport() > 0){
            if( unsigned(j+1) != singleColumnImport()){
                to_be_removed.push_back(j);
                continue;
            }
        }

        int i = 0;
        bool this_col_is_blank = cell_is_blank(i,j);
        while(this_col_is_blank && i < nRows  ){
            this_col_is_blank = cell_is_blank(i,j);
            i++;
        }
        if(i == nRows){
            to_be_removed.push_back(j);
        }
    }

    //save the values of the array
    for(int i = 0; i < nRows; i++){
        StringVector.clear();
        for(int j = 0; j < nCols; j++){
            string contents = m_tableWidget->item(i,j) != nullptr ? m_tableWidget->item(i,j)->text().toStdString() : "";
            StringVector.push_back(contents);
        }
        //Skip last row if it is an empty line:
        if(i == nRows - 1)
            if(QString::fromStdString(accumulate(StringVector.begin(), StringVector.end(), string(""))).trimmed() == "")
                continue;

        StringVectorVector.push_back(StringVector);
    }

    //correct the size of the table
    m_tableWidget->clearContents();
    m_tableWidget->setRowCount(0);
    m_tableWidget->setColumnCount(nCols-int(to_be_removed.size()));
    nRows = int(StringVectorVector.size());

    //put values into a new table
    for(int i = 0; i < nRows; i++){
        m_tableWidget->insertRow(m_tableWidget->rowCount());
        int J = 0;
        for(int j = 0; j < nCols; j++){
            if( std::find(to_be_removed.begin(), to_be_removed.end(), j) == to_be_removed.end()){
                string retrievedString = StringVectorVector[unsigned(i)][unsigned(j)];
                m_tableWidget->setItem(i,J,new QTableWidgetItem(QString::fromStdString(retrievedString)));
                J++;
            }
        }
    }

    //set header labels:
    QStringList headers;
    for(int j = 0; j < nCols; j++)
        if( std::find(to_be_removed.begin(), to_be_removed.end(), j) == to_be_removed.end())
            headers.append(QString::fromStdString(string("Column ") + to_string(j+1)));
    m_tableWidget->setHorizontalHeaderLabels(headers);
}

void CsvImportAssistant::setRowNumbering(){

    unsigned firstDataLine = firstLine();
    unsigned lastDataLine = lastLine();


    QStringList displayRowNumbers;
    for(unsigned i = firstDataLine; i <= lastDataLine; i++)
        displayRowNumbers << QString::number(i);

    m_tableWidget->setVerticalHeaderLabels(displayRowNumbers);
}


bool CsvImportAssistant::cell_is_blank(int iRow, int jCol){

    if ( m_tableWidget->item(iRow,jCol) == nullptr)
        return true;

    if ( m_tableWidget->item(iRow,jCol)->text() == nullptr)
        return true;

    if( m_tableWidget->item(iRow,jCol)->text().trimmed() == "")
        return true;

    return false;
}

QString CsvImportAssistant::filepath() const{
    return m_filePathField->text().trimmed();
}

void CsvImportAssistant::setFilepath(QString fpath){
    m_fileName = fpath;
    m_filePathField->setText(m_fileName);
}

char CsvImportAssistant::separator() const{
    char separator;
    QString tmpstr = m_separatorField->text();
    if(tmpstr.size() < 1){
        separator = guessSeparator();
        QMessageBox msgBox;
        msgBox.setText("There was a problem with the separator given.\n Replacing it by ' ' [space]");
        msgBox.setIcon(msgBox.Information);
        msgBox.exec();
        m_separatorField->setText(QString(QChar::fromLatin1(separator)));
    }
    else{
        separator = tmpstr.at(0).toLatin1();
    }
    return separator;
}

char CsvImportAssistant::guessSeparator() const{
    int frequencies[127] = {0};

    //The actual characters that may be realistically
    //used as separators are only a handfull...
    //And this list seems already exagerated.
    vector<char> preferredSeparators;
    preferredSeparators.push_back(' ');
    preferredSeparators.push_back(',');
    preferredSeparators.push_back(';');
    preferredSeparators.push_back('|');
    preferredSeparators.push_back(':');
    preferredSeparators.push_back('\t');
    preferredSeparators.push_back('/');
    preferredSeparators.push_back('\\');
    preferredSeparators.push_back('_');
    preferredSeparators.push_back('\'');
    preferredSeparators.push_back('\"');


    //count number of occurences of each char in the file:
    char c;
    ifstream is(m_fileName.toStdString());
    while (is.get(c))
        frequencies[int(c)]++;
    is.close();

    //set the guessed separator as the most frequent among the
    //preferred separators. -- Some unavoidable hieararchy is
    //present: characters with lower ascii code are preferred.
    char guessedSep = ' ';
    int freq = 0;
    for(char i = 0; i< 127 ; i++){
        if( std::find(preferredSeparators.begin(), preferredSeparators.end(), i) != preferredSeparators.end())
            if(frequencies[int(i)] > freq){
                freq = frequencies[int(i)];
                guessedSep = i;
            }
    }

    //We don't like tabs, as we cannot write them in the GUI.
    //The rest of the CsvImportAssistant and CsvReader should be already aware of this.
    if(guessedSep == '\t')
        guessedSep = ' ';

    return guessedSep;
}

unsigned CsvImportAssistant::headersLine() const{
    return 0;//m_headersRowSpinBox->value();
}

unsigned CsvImportAssistant::firstLine() const{
    return unsigned(m_firstDataRowSpinBox->value());
}

unsigned CsvImportAssistant::lastLine() const{
    return m_lastDataRow;
}

unsigned CsvImportAssistant::singleColumnImport() const{
    return unsigned(m_singleDataColSpinBox->value());
}

void CsvImportAssistant::OnColumnClicked(int row, int column)
{
    if(column < 0) return;
    if(row < 0) return;


    QModelIndex left = m_tableWidget->model()->index(row, 0);
    QModelIndex right= m_tableWidget->model()->index(row, m_tableWidget->columnCount() - 1);
    QModelIndex top = m_tableWidget->model()->index(0, column);
    QModelIndex bottom = m_tableWidget->model()->index(m_tableWidget->rowCount() - 1, column);


    QItemSelection selection(left, right);
    selection.merge(QItemSelection(top, bottom), QItemSelectionModel::Select);
    m_tableWidget->selectionModel()->select(selection, QItemSelectionModel::Select);
}

void CsvImportAssistant::onColumnRightClick(const QPoint position)
{
    auto item = m_tableWidget->itemAt(position);
    if(!item) return;
    auto row = item->row();
    auto col = item->column();

    if(row*col < 0) return;

    OnColumnClicked(row,col);
    QMenu menu;



    //Set column as "Intensity"
    menu.addAction( "Set as " + relevantHeaders[_intensity_]);
    connect(menu.actions()[_intensity_],&QAction::triggered,
       [&](){
        QString originalHeader = m_tableWidget->horizontalHeaderItem(col)->text();
        int columnInFile = originalHeader.split(' ').takeLast().toInt();
        m_tableWidget->setHorizontalHeaderItem( col, new QTableWidgetItem( relevantHeaders[_intensity_]) );
        m_singleDataColSpinBox->setValue(columnInFile);
        Reload();
    }
    );


    //Set column as "Theta"
    menu.addAction( "Set as " + relevantHeaders[_theta_]);
    connect(menu.actions()[_theta_],&QAction::triggered,
            [&](){m_tableWidget->setHorizontalHeaderItem( col, new QTableWidgetItem( relevantHeaders[_theta_]) );}
    );


    //Set column as "2Theta"
    menu.addAction( "Set as " + relevantHeaders[_2theta_]);
    connect(menu.actions()[_2theta_],&QAction::triggered,
            [&](){m_tableWidget->setHorizontalHeaderItem( col, new QTableWidgetItem( relevantHeaders[_2theta_]) );}
    );


    //Set column as "qvector"
    menu.addAction( "Set as " + relevantHeaders[_q_]);
    connect(menu.actions()[_q_],&QAction::triggered,
            [&](){m_tableWidget->setHorizontalHeaderItem( col, new QTableWidgetItem( relevantHeaders[_q_]) );}
    );

    menu.addSeparator();

    //Action "select from this row"
    QAction selectFromThisRowOn("Ignore preceding rows");
    menu.addAction(&selectFromThisRowOn);
    connect(&selectFromThisRowOn,&QAction::triggered,
            [&](){m_firstDataRowSpinBox->setValue(m_tableWidget->verticalHeaderItem(row)->text().toInt());}
    );

    menu.addSeparator();

    //Action "reset"
    QAction reset("reset");
    menu.addAction(&reset);
    connect(&reset,&QAction::triggered,
            [&](){
                m_firstDataRowSpinBox->setValue(0);
                m_singleDataColSpinBox->setValue(0);
            }
    );

    menu.exec(m_tableWidget->mapToGlobal(position));
}

void CsvImportAssistant::onReloadButton(){
    Reload();
}

void CsvImportAssistant::onIntChanged(int _){
    Reload();
}
