# Lab 10: File Handling and Recursion

Solutions to the Lab 10 tasks for Programming at FAST-NUCES, Karachi. All programs are written in C.

## Topics Covered

- **File handling:** `fopen()` modes (`"wb"`, `"rb+"`, `"ab"`), `fprintf()`, `fscanf()`, `fseek()`, `rewind()`, `fclose()`
- **Random access in files:** jumping straight to a record with `fseek(fp, (n - 1) * recordSize, SEEK_SET)`, and reading from the end with `SEEK_END`
- **Recursion on arrays:** processing the last element, then calling the function for `n - 1`
- **Recursion on a 2D array:** flood fill
- **Recursion on strings:** character counting and run-length compression


## Questions

| # | File | Task | Main Idea |
|---|------|------|-----------|
| 1 | `Queston #1.c` | FreshMart billing (`items.txt`, 42-byte records) | `fseek()` to an item, read it, reduce stock, write it back |
| 2 | `Question #2.c` | Student attendance (`attendance.txt`, 24-byte records) | Attendance percentage, add leave lectures, last record with `SEEK_END` |
| 3 | `Question #3.c` | City temperatures (`temperature.txt`, 17-byte records) | Read one city, correct a reading, find the hottest city with `rewind()` |
| 4 | `Question #4.c` | Hotel rooms (`hotel.txt`, 39-byte records) | Check-in, search by name with `strcmp()`, check-out bill |
| 5 | `Question #5.c` | Expense tracker (`expenses.txt`, 23-byte records) | Append mode, last two records, fix an entry, total |
| 6 | `Question #6.c` | Tower heights | Recursive `grow()`, `tallest()` and `search()` |
| 7 | `Question #7.c` | Weekly bank transactions | Recursive `finalBalance()`, `totalDeposits()`, `copyLarge()` |
| 8 | `Question #8.c` | Patient health scores | Recursive `buildScores()`, `countLow()`, `reverse()` |
| 9 | `Question #9.c` | Frost zones on a 5 x 5 grid | Recursive `markZone()` (flood fill) |
| 10 | `Question #10.c` | String compression | Recursive `countRepeat()`, `compress()`, `expand()` |



## Notes

- Files in Questions 1 to 5 are created with `"wb"` (binary mode) so that every record keeps its exact size on Windows too. In text mode, Windows adds an extra `\r` on each line, which would break the `fseek()` positions.
- Each record has a fixed size, so the position of record `n` is always `(n - 1) * recordSize`.
- In Question 9, the PDF cuts off one grid value (`-2.`), so `-2.0` is used. This matches the sample output.
- The data files (`items.txt`, `hotel.txt`, and so on) are created automatically when you run the programs.

## Author
- Name: Mohammad Ahmed
- ID: 26K-0662
- BSCS student at FAST-NUCES Karachi.
