import pandas as pd
import sys
import numpy as np
import json

inFile = sys.argv[1]
outFile = "outfile.json"
inp, = pd.read_html(inFile, header=0, parse_dates=["Language"])
inpDICT = inp.to_dict(orient="records")
inpJSON = inp.to_json(orient="records", date_format="iso")
jfile = json.loads(inpJSON)

for sound in jfile:
    for attribute, value in sound.items():
        if attribute == "Language":
            curLanguage = value
            print(curLanguage)
        else:
            curDefinition = attribute
            curSound = value
            print(curDefinition)
            print(curSound)