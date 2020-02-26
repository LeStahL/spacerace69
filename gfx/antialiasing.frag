/* Demo engine code - Team210
 * Copyright (C) 2019 Alexander Kraus <nr4@z10.info>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#version 130

out vec4 gl_FragColor;

uniform float iFSAA, 
    iWidth;
uniform vec2 iResolution;
uniform sampler2D iChannel0;
    
const vec3 c = vec3(1.,0.,-1.);

void rand(in vec2 x, out float n);

void main( )
{
    gl_FragColor = c.yyyy;
    vec2 r;
    for(float i = 0.; i < iFSAA; i += 1.)
    {
        rand(i*c.xx, r.x);
        rand(i*c.xx+1337., r.y);
        gl_FragColor += texture(iChannel0, (gl_FragCoord.xy+iWidth*(-.5+r))/iResolution.xy);
    }
    gl_FragColor /= iFSAA;
}
