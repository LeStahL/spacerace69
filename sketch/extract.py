# Hardcyber - PC-64k-Intro by Team210 at Deadline 2k19
# Copyright (C) 2019  Alexander Kraus <nr4@z10.info>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

from svgpathtools import Path, Line
from svgpathtools import parse_path

path_string = 'm 132.57964,132.64335 3.45722,4.55083 h -22.08389 l 3.4925,-4.55083 1.48167,-1.94028 v 1.94028 h 6.77333 l -1.41111,-1.83444 h -1.79917 l -4.05694,-5.29167 h 4.19805 l 2.2225,-2.92806 v 0.0353 l 0.56445,-0.74083 h -6.49111 v 1.94028 l -1.48167,-1.94028 -4.02166,-5.25639 h 22.61305 l -3.98639,5.25639 -2.82222,3.63361 h 1.86972 l -1.97555,2.64583 z m -33.45987,-1.83444 -1.411111,1.83444 h 9.172221 l 3.45722,4.55083 H 88.254216 l 0.03528,-0.0353 h -0.564445 l 4.797778,-6.35 h -0.03528 l 4.056944,-5.29167 h 1.340555 l 2.786942,-3.63361 h -7.443608 v 1.94028 l -1.481667,-1.94028 -4.021666,-5.25639 h 23.495001 l -10.68917,14.18167 z'

path = parse_path(path_string)

# find dimensions
xmax = -1.e9
xmin = 1.e9
ymax = -1.e9
ymin = 1.e9
for line in path:
    xmax = max(xmax, line.start.real)
    xmax = max(xmax, line.end.real)
    
    xmin = min(xmin, line.start.real)
    xmin = min(xmin, line.end.real)
    
    ymax = max(ymax, line.start.imag)
    ymax = max(ymax, line.end.imag)
    
    ymin = min(ymin, line.start.imag)
    ymin = min(ymin, line.end.imag)

# rescale path
for i in range(len(path)):
    path[i].start -= complex(xmin,ymin)
    path[i].start = complex(path[i].start.real/abs(xmax-xmin), path[i].start.imag/abs(ymax-ymin)/100.*29.)
    path[i].start -= complex(.5,.5*29./100.)
    path[i].start = complex(path[i].start.real,-path[i].start.imag)
    
    path[i].end -= complex(xmin,ymin)
    path[i].end = complex(path[i].end.real/abs(xmax-xmin), path[i].end.imag/abs(ymax-ymin)/100.*29.)
    path[i].end -= complex(.5,.5*29./100.)
    path[i].end = complex(path[i].end.real,-path[i].end.imag)

# sort path
#newpath = [ path[0] ]
#del path[0]
#while len(path) > 1:
    #print(len(path))
    #for j in range(len(path)-1):
        #print(j,"/",len(path))
        #if abs(newpath[-1].end - path[j].start)<5.e-1:
            #newpath += [ path[j] ]
            #del path[j]
            #break
#path = newpath
    
with open('dreiundzwanzig.frag', 'wt') as f:
    f.write('const int npts = ' + str(4*len(path)) + ';\n')
    f.write('const float path[npts] = float[npts](')
    
    for i in range(len(path)-1):
        line = path[i]
        f.write('{:.3f}'.format(line.start.real) + ',' + '{:.3f}'.format(line.start.imag) + ',')
        f.write('{:.3f}'.format(line.end.real) + ',' + '{:.3f}'.format(line.end.imag) + ',')
    line = path[-1]
    f.write('{:.3f}'.format(line.start.real) + ',' + '{:.3f}'.format(line.start.imag) + ',')
    f.write('{:.3f}'.format(line.end.real) + ',' + '{:.3f}'.format(line.end.imag))
    f.write(');\n')
    f.close()
