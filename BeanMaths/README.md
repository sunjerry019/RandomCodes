# BeanMaths

[![forthebadge](https://forthebadge.com/images/badges/made-with-python.svg)](https://forthebadge.com)

Scripts to generate maths practice questions for my sister, who was in primary school, based on certain parameters (such as addition and subtraction less than 100). <br>
Output was generated as a latex file, and then compiled with `pdflatex`. Answers are also generated for easy checking.

All sums are randomly generated. Repeats are also avoided as much as possible; all combinations must have been exhausted before problems begin to repeat. Multiple worksheets can also be generated on demand for daily practice.

It was made as an improvement over the Excel file that my parents have been using.

## [Problems](/sunjerry019/RandomCodes/tree/master/BeanMaths/problems)

The collection of already generated problem sets can be found here

[bean.py](/sunjerry019/RandomCodes/blob/master/BeanMaths/bean.py) is used to generate questions that involve operations of numbers between l_limit and h_limit
[bean2.py](/sunjerry019/RandomCodes/blob/master/BeanMaths/bean2.py) is used to generate 100 - x where 0 < x < 100
