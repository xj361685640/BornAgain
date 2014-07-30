#!/usr/bin/env python

import sys
import os
import subprocess

RELEASE_WORKING_DIRECTORY = ""
RELEASE_BRANCH_NAME = ""


def get_working_dir():
    return RELEASE_WORKING_DIRECTORY


def get_source_dir():
    return get_working_dir()+"/"+"BornAgain"


def get_build_dir():
    return get_working_dir()+"/"+"build"


def get_upload_dir():
    return get_working_dir()+"/"+"upload"


def get_install_dir():
    return get_working_dir()+"/"+"installed"


def get_branch_name():
    return RELEASE_BRANCH_NAME


def get_version():
    name, version = get_branch_name().split("-")
    return version


def run_command(cmd):
    returncode = os.system(cmd)
    if returncode:
        exit("Error while running command '"+cmd+"'")


def make_directories():
    os.makedirs(get_working_dir())
    os.makedirs(get_build_dir())
    os.makedirs(get_upload_dir())
    os.makedirs(get_install_dir())


def git_clone():
    print "Cloning BornAgain repository ... ",
    cmd = "cd %s; git clone git@apps.jcns.fz-juelich.de:BornAgain.git" % get_working_dir()
    run_command(cmd)
    cmd = "cd %s; git checkout %s" % (get_working_dir(), get_branch_name())
    run_command(cmd)


def download_from_app_server():
    print "Downloading from application server ..."
    cmd = "rsync -avzhe ssh apps@apps.jcns.fz-juelich.de:/www/apps/src/BornAgain/ %s" %get_upload_dir()
    run_command(cmd)


def cmake_release():
    print "Running cmake ...", get_build_dir()
    cmd = "cd %s; cmake -DBORNAGAIN_APP=ON -DBORNAGAIN_MAN=ON -DBORNAGAIN_RELEASE=ON -DCMAKE_INSTALL_PREFIX %s %s" % (get_build_dir(), get_install_dir(), get_source_dir() )
    run_command(cmd)


def compile_release():
    print "Compiling ..."
    cmd = "make --directory %s -j8; make check; make install" % get_build_dir()
    run_command(cmd)


def measure_performance():
    print "Measuring performance ..."
    perf_txt = get_source_dir()+"/dev-tools/log/perf_history.txt"
    cmd = "cd %s; ./bin/App --performance --batch; " % get_build_dir()
    run_command(cmd)
    cmd = "echo \"# Release %s\" >> %s" % (get_version(), perf_txt)
    run_command(cmd)
    cmd = "cat perf_history.txt >> %s" % perf_txt
    run_command(cmd)


def make_tarball():
    print "Making tarball ..."
    run_command("cd %s; make package_source" % get_build_dir())


def update_upload_dir():
    print "Updating directory for upload ..."
    run_command("mv %s/BornAgain*.tar.gz %s/old" % (get_upload_dir(), get_upload_dir()))
    run_command("mv %s/BornAgain*-win32.exe %s/old" % (get_upload_dir(), get_upload_dir()))
    run_command("cp %s/BornAgain-%s.tar.gz %s" % (get_build_dir(), get_version(), get_upload_dir()))


def parse_release_name(release_branch_name):
    name, version = release_branch_name.split("-")
    version_major, version_minor, version_patch = version.split(".")
    print version_major, version_minor, version_patch
    return version_major, version_minor, version_patch


def prepare_release():
    print "Preparing release %s in working directory '%s'." % (get_version(), get_working_dir())

    #make_directories()
    #git_clone()
    #download_from_app_server()
    #cmake_release()
    #compile_release()
    #measure_performance()
    #make_tarball()
    #update_upload_dir()

    print "New %s release is successfully created in the %s. Please check it now ;-)" % (get_version(), get_working_dir())
    print "After your are done, run this script again."

def main():
    global RELEASE_BRANCH_NAME
    global RELEASE_WORKING_DIRECTORY

    if len(sys.argv) != 2:
        print "Please specify the name of the release branch."
        print "Usage: python make_release.py release-0.9.3"
        exit()

    RELEASE_BRANCH_NAME = sys.argv[1]
    RELEASE_WORKING_DIRECTORY = os.getcwd() + "/" + RELEASE_BRANCH_NAME

    #if os.path.exists(get_working_dir()):
    #    print "Directory %s exists, continuing release process." % get_working_dir()
    #else:
    #    prepare_release()

    prepare_release()



if __name__ == '__main__':
    main()
