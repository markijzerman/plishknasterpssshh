import pandas as pd
import sys
import json
from unidecode import unidecode
import re

inFile = sys.argv[1]
outFile = "outfile.json"
inp, = pd.read_html(inFile, header=0, parse_dates=["Language"])
inpDICT = inp.to_dict(orient="records")
inpJSON = inp.to_json(orient="records", date_format="iso")
jfile = json.loads(inpJSON)

stringNr = 0 # start with this nr

for sound in jfile:
    for attribute, value in sound.items():
        if attribute == "Language":
            curLanguage = value
        else:
            curDefinition = attribute
            curSound = value
            curComplete = [curSound, curDefinition, curLanguage]
            if curComplete[0] != None: # als ie geen geluid heeft, print niet.
                # hier ook checken of er gekke karakters in zitten
                curComplete[0] = unidecode(curComplete[0])
                isItReadable = bool(re.match('^[a-zA-Z-()]+$', curComplete[0]))
                if isItReadable == True:
                    # print (curComplete[0], curComplete[1], curComplete[2])
                    print ("const char string_%s[] PROGMEM = %s (%s) (%s)" % (stringNr, curComplete[0], curComplete[1], curComplete[2]))
                    stringNr = stringNr + 1