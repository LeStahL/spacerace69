# Spacerace 69 - Evoke 2k20 invitation by Team210 shown at Revision 2k20
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

import argparse, json, os.path

def authorJSON(authorName, demoJSON):
    for author in demoJSON['authors']:
        if author['handle'] == authorName:
            return author
    print("Requested author does not exist.")
    return 0

parser = argparse.ArgumentParser(description='Team210 generator tool.')
args, rest = parser.parse_known_args()

if rest == []:
    print('No input file present. Can not do anything.')
    exit()

f = open(rest[0], 'rt')
demoJSON = json.load(f);

### Generate :/config.gen.cmake
f = open('config.gen.cmake', 'wt')

demoId = demoJSON['identifier']
demoGroup = demoJSON['group']
demoParty = demoJSON['party']
partyYear = demoJSON['year']

# Target name
f.write('set(DEMO_IDENTIFIER ' + demoId + ')' + '\n')

# Scene shader files
f.write('set(SHADER_FILES\n')
for scene in demoJSON["scenes"]:
    filename = 'gfx/' + scene["fragment"]
    
    # Create default shader (that compiles) if shader is not present.
    if not os.path.exists(filename):
        g = open(filename, "wt")
        g.write("/* " + demoId + " - PC64k intro by " + demoGroup + ' at ' + demoParty + str(partyYear) + '\n')
        for author in scene['authors']:
            authorData = authorJSON(author['name'], demoJSON)
            print(author['name'])
            g.write(" * Copyright (C) " + str(partyYear) + " " + authorData['realname'] + ' <' + authorData['email'] + '>\n')
        g.write(' *\n')
        g.write(' * This program is free software: you can redistribute it and/or modify\n')
        g.write(' * it under the terms of the GNU General Public License as published by\n')
        g.write(' * the Free Software Foundation, either version 3 of the License, or\n')
        g.write(' * (at your option) any later version.\n')
        g.write(' *')
        g.write(' * This program is distributed in the hope that it will be useful,\n')
        g.write(' * but WITHOUT ANY WARRANTY; without even the implied warranty of\n')
        g.write(' * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n')
        g.write(' * GNU General Public License for more details.\n')
        g.write(' *\n')
        g.write(' * You should have received a copy of the GNU General Public License\n')
        g.write(' * along with this program.  If not, see <https://www.gnu.org/licenses/>.\n')
        g.write(' */\n')
        g.write('\n')
        g.write('#version 130\n')
        g.write('\n')
        g.write('void main()\n')
        g.write('{\n')
        g.write('}\n')
        g.close()
    
    # Add filename to scenes list
    f.write('    ' + filename + '\n')
    
f.write(')\n')
f.close()
