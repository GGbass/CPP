ex00 Bitcoin Exchange — details and implementation hints
Use a small Date type (struct with year, month, day) and overload operator< so it can be a std::map key;
parse dates robustly and validate ranges before inserting/looking up.

Populate a std::map<Date, double> from the provided CSV database (date -> price).
For each input line: parse date and value, validate value range (0..1000, float allowed).

To get the correct rate when input date is missing: use it = db.upper_bound(date); if it == db.begin() 
then no lower date exists → error; otherwise --it gives the greatest key <= date (the required lower date).

Error cases to cover: file open, bad date format, non-positive number, >1000, overflow, malformed line. Print exact messages as subject examples.

Why map: ordered keys and O(log n) lookup; upper_bound provides the "closest lower date" semantics directly.