#!/bin/python3

"""
To generate 100 - x where 0 < x < 100
"""

import random
from subprocess import call
import os

# <customizations>
total = 100
no_of_probs = 40
no_of_cols = 4
itemsep = "2\\baselineskip" #0.45 for 100, 2.3 for 50
vfill = False
show = False
# </customizations>
operators = ["-"]
numbers= []
problems = []
operatorMap = {"+": "+", "-": "-", "\\times": "*", "\\div": "/"}
nameMap = {"+": "Addition", "-": "Subtraction", "\\times": "Multiplication", "\\div": "Division"}

out = open("temp.tex","w")

def getTypes():
	ausgabe = []
	for op in operators:
		ausgabe.append(nameMap[op])
		ausgabe.append(", ")
	ausgabe = ausgabe[:-1]
	if len(operators) > 1:
		ausgabe[-2] = " and "

	return "".join(ausgabe)

def ans(evalProb):
	evalProb[1] = operatorMap[evalProb[1]]
	return eval("".join(evalProb))

for i in range(no_of_probs):
	while True:
		a = random.randint(1, total - 1)

		if len(numbers) < total:
			if a not in numbers:
				numbers.append(a)
				break
		else:
			break
	op = operators[0]

	problems.append([str(total), op, str(a)])

out.write("\\documentclass[11pt]{article}\\usepackage[a4paper,margin=0.90in,tmargin=0.5in]{geometry}\\usepackage{amsmath, amsthm, amssymb}\n")
out.write("\\usepackage[type1]{libertine}\n")
out.write("\\usepackage{multicol}\n")
out.write("\\usepackage{enumitem}")
out.write("\\usepackage[usenames,dvipsnames,svgnames,table]{xcolor}")

out.write("\\newcommand{\\addstretch}[1]{\\addtolength{#1}{\\fill}}\n")

#out.write("\\title{Maths Practice (Addition and Subtractions)}\n")
out.write("\\title{{Maths Practice ({})}}\n".format(getTypes()))
out.write("\\raggedbottom\n")

out.write("\\begin{document}\n")

out.write("\\maketitle\n")

# out.write("\\addstretch{\\baselineskip}\n\\addstretch{\\abovedisplayskip}\n\\addstretch{\\abovedisplayshortskip}\n\\addstretch{\\belowdisplayskip}\n\\addstretch{\\belowdisplayshortskip}\n\\addstretch{\\itemsep}")

out.write("\\begin{{multicols{}}}{{{}}}\n".format("*" if vfill else "", no_of_cols))
# out.write("\\raggedcolumns")
out.write("\\begin{{enumerate}}[itemsep={},label={{[\\arabic*]}}]\n".format(itemsep))

for prob in problems:
	# out.write("\\item ${} =$ \n".format(" ".join(prob)))												# 100 - x = ?
	out.write("\\item ${} {} \\framebox[1cm][c]{{ \\parbox[t]{{\\dimexpr\\linewidth-2\\fboxsep-2\\fboxrule}}{{\\raggedright\\strut~}} }} = {}$ \n".format(prob[0], prob[1], prob[2]))		# 100 - ? = x

out.write("\\end{enumerate}\n")
out.write("\\vfill\n" if vfill else "") 
out.write("\\end{{multicols{}}}\n".format("*" if vfill else ""))

out.write("\\newpage")

out.write("\\vspace{\\baselineskip}\n\\begin{center}\n{\\Huge Answers}\n\end{center}\n\\vspace{0.5\\baselineskip}")

out.write("\\begin{{multicols{}}}{{{}}}\n".format("*" if vfill else "", no_of_cols))
# out.write("\\raggedcolumns")
out.write("\\begin{{enumerate}}[itemsep={},label={{[\\arabic*]}}]\n".format(itemsep))

for prob in problems:
	# out.write("\\item ${} = {{ \\color[rgb]{{0,0,1}} {} }}$ \n".format(" ".join(prob), ans(prob)))	# 100 - x = ?
	out.write("\\item ${} {} {{ \\color[rgb]{{0,0,1}} \\framebox[1.1\\width][c]{{ ${}$ }} }} = {}$ \n".format(prob[0], prob[1], ans(prob), prob[2]))

out.write("\\end{enumerate}\n")
out.write("\\vfill\n" if vfill else "") 
out.write("\\end{{multicols{}}}\n".format("*" if vfill else ""))

out.write("\\end{document}\n")

out.close()

fdir = os.path.dirname(os.path.realpath(__file__))
call(["pdflatex", "-output-directory=" + fdir, "temp.tex"])
call(["rm", os.path.join(fdir, "temp.aux"), os.path.join(fdir, "temp.log")])
if show:
	call(["evince", os.path.join(fdir, "temp.pdf")])

# https://tex.stackexchange.com/questions/167454/how-to-change-the-label-of-one-item-in-an-enumitem-list