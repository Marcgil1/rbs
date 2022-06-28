# Rule-Based System

## Introduction
This project implements a rule-based system with certainty factors. In this
introduction, we will present what these concepts mean.

A rule-based system serves as a logical-deduction machine, being given as inputs
some facts, and some logical rules relating these facts, so that we may check
whether a given conclussion holds. For example, suppose we are given the
following rules:

```
IF shinyDay AND haveTimeForPrograming, THEN iAmInAGoodMood
IF shinyDay,                           THEN itsHotOutside
```

If we know that today is shiny, we may say that ```shinyDay``` holds, and, by
the second rule above, ```itsHotOutside``` also holds.  However, if we don't
know that ```haveTimeForProgramming``` also holds, we cannot infer
that ```iAmInAGoodMood```, for not all premises in the first rule hold. A
rule-based system follows a similar reasoning for answering questions in this
framework.

However, this scheme is unsuitable for many situations, because not every
deduction follows the simple schema of *A IMPLIES B*. Certainty factors try to
introduce the concept of *degree of belief*, so that we may represent the case
in which a fact holds with some certainty. For instance, we may say today its
*80% shiny*, which may be more accurate than saying it's *100% shiny*.
Furthermore, we may quantify the degree of certainty we have in the validity of
some rule, so that the second rule above could be

```
IF shinyDay, THEN itsHotOutside, with 70% certainty
```

The rule-based system implemented in this project includes certainty factors for
determining the degree of certainty with which a conclussion holds given some
facts, some inference rules, and the degree of confidence in both facts and
rules.

## Uses
Rule-based systems are suitable for situations in which some decissions must be
taken according to some available data and to some previouly-recorded rules. For
instance, they may be used in the medical domain, for determining the best
treatment to give to some patient provided his pathologies and symptoms.
The key requirement is the availability of previously recorded expert knowledge.

These systems have the great advantage of being highly interpretable. That is,
we may check the reasoning followed for arriving to some conclussion.

## Execution
The program requires two parameters, the files holding a knowledge base and a
fact base. The program will create a file whose name will be the concatenation
of the other two files', containing the parameters of execution, the certainty
of the conclussion, and the reasoning process followed for arriving to the
conclussion.

## Environment
This project uses the [build2](https://build2.org) build toolchain. With it
installed, one may call the command ```b``` (bundled with the toolchain) in the
source folder for creating the executable. No external dependencies are used.
