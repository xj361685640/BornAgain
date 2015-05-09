"""
Plot form factors of pyramids for different rotations.
"""
import bornagain as ba
from   bornagain import nanometer, degree, angstrom, deg2rad
import bornplot as bp

det = bp.Detector( 200, 0, 5, 0, 5 )
n    = 4
results = []
for i in range(n):
    omega=45*i/(n-1)
    title = r'$\omega=%d^\circ$' % omega
    ff = ba.FormFactorPyramid(10*nanometer, 5*nanometer, deg2rad(54.73))
    trafo = ba.RotationZ(omega*degree)
    data = bp.run_simulation(det,ff,trafo)
    results.append( bp.Result(i, data, title) )
    
bp.make_plot( results, det, "pyramid" )
