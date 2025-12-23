# Bitcoin Exchange
Step	Action	Logic infile
1	Open	Check if file infile exists.
2	Read	Get one line from the file.
3	Split	Separate the date from the value using the comma.
4	Clean	Use trimString to remove spaces.
5	Verify	Check if the date is real and the number is valid.
6	Lookup	Find the price of Bitcoin on that date.
7	Print	Show the final calculation to the user.
8	Repeat	Go back to step 2 until the end of the file.