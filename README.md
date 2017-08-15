# cumulative-voting

In this question we will implement an election that uses cumulative voting. In this voting
scheme, a voter has X number of votes that they can choose to distribute among the candi-
dates which are numbered from 1 to n, where n is at most 10 (the edge case of 0 candidates
is possible and is considered valid input). The value for X may be provided as an optional
positive command line argument. If a value of X is not provided as an argument, the default
value of n is used. Input begins with the names of candidates (one full name per line). The
rst name is considered as candidate 1, and second as candidate 2, and so on. A candidate's
name will never contain a numeral and consists of at least 1 and at most 15 characters (in-
cluding any spaces). The list of candidates is followed by some number of lines where each
line indicates one voter's distribution of votes, which we call a ballot. For a ballot the ith
column indicates the number of votes allocated to the ith candidate. A ballot is considered
invalid (spoilt) if it does not consist of n columns or the sum of the votes in the ballot ex-
ceeds X. In addition, the votes allocated to a specic candidate within a ballot are always
non-negative. The number of voters is unknown beforehand, but is, of course, non-negative.
Votes are terminated by end-of-le.
As an example, given the following data:
Victor Taylor
Denise Duncan
Kamal Ramdhan
Michael Ali
Anisa Sawh
Carol Khan
Gary Owen
3 0 1 0 0 1 2
1 1 1 1 0 1 2
1 1 1 1 1 1 1
2 1 3 1
7 0 0 0 0 0 0
1 1 1 1 1 1 2


your program should produce the following output:
Number of voters: 6
Number of valid ballots: 4
Number of spoilt ballots: 2
Candidate Score
Victor Taylor 12
Denise Duncan 2
Kamal Ramdhan 3
Michael Ali 2
Anisa Sawh 1
Carol Khan 3
Gary Owen 5
Use the following format for the data in the two columns:
 Candidate: left-justied, 15 characters wide
 Score: right-justied, 3 characters wide
