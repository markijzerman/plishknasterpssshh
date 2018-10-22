import sys
import pandas as pd
import requests
from bs4 import BeautifulSoup
from unidecode import unidecode
import re

inFile = sys.argv[1]
outFile = "listOut.txt"
listSound = sys.argv[2]

soup = BeautifulSoup(open(inFile).read(),'lxml')

for ul in soup:
    for li in ul.findAll('li'):
        curComplete = [li.find('i').contents[0], listSound, li.find('a').contents[0]]
        # print(curComplete)
        if curComplete[0] != None: # als ie geen geluid heeft, print niet.
                # hier ook checken of er gekke karakters in zitten
                curComplete[0] = unidecode(curComplete[0]) #replace gekke karakters
                isItReadable = bool(re.match('^[a-zA-Z-()\s]+$', curComplete[0])) #laat nu alleen leesbare strings door
                if isItReadable == True:
                    s = curComplete[0]
                    findParenthesis = set('()') # vind tekst tussen haakjes
                    if any((c in findParenthesis) for c in curComplete[0]):
                        newString = s[s.find("(")+1:s.find(")")]
                        if len(newString) > 1: # als dit meer dan 1 karakter is, is het wrsch fijn en fonetisch
                            curComplete[0] = newString
                    # print (curComplete[0], curComplete[1], curComplete[2])
                    print ("%s (%s) (%s)" % (curComplete[0], curComplete[1], curComplete[2]))
        