# C10 — File I/O & System Calls

Instead of `fopen`/`fread`/`fprintf` from the standard library, this module works directly with the lower-level POSIX syscalls: `open`, `read`, `write`, `close`. You're essentially rebuilding small versions of real Unix tools.

## Exercises

| Ex | Concept it's testing |
|---|---|
| `ex00` ft_display_file | Reading a file's full contents and printing it |
| `ex01` ft_cat | A more complete `cat`-like tool, with multiple files and error handling |
| `ex02` ft_tail | Reading a file and working with only part of its contents |
| `ex03` ft_hexdump | Formatting raw bytes as a hex + ASCII dump |

## Tips & tricks

- **`open`, `read`, `write`, `close` are your only tools here** — no `fopen`/`fgets`/`fprintf`. `read()` fills a buffer and returns the number of bytes actually read (which can be *less* than you asked for, and is `0` at end-of-file, and negative on error) — your loop has to handle all three cases correctly.
- **Always check `open()`'s return value.** It returns `-1` on failure (file doesn't exist, no permission, etc.) — a program that doesn't check this will crash confusingly instead of failing gracefully.
- **For `ft_cat` with multiple files**, decide what happens when one file in the list fails to open: the well-behaved answer is to print an error for that one file (to `stderr`, conventionally) and continue with the rest, rather than stopping the whole program.
- **`ft_hexdump`-style output has a very specific format** (offset, hex bytes grouped in a particular way, then the printable-character sidebar) — run the real `hexdump -C` on a small test file and compare your output byte-for-byte before assuming your formatting logic is right.
- **Buffer size matters for correctness, not just speed** — a `read()` loop must keep reading until it gets `0` bytes back (EOF), not assume one `read()` call gets you the whole file.

## Resources

- `man 2 open`, `man 2 read`, `man 2 write`, `man 2 close` — read all four; this module is essentially "learn these four syscalls properly."
- `man hexdump` — run `hexdump -C somefile` yourself and study the output format.
- [Beej's Guide — low-level I/O basics](https://beej.us/guide/bgc/html/split/) — good background on why syscalls behave the way they do.

## Don't

Don't assume `read()` always fills your whole buffer in one call — it's one of the most common bugs in this module and the fix (loop until you've read everything or hit EOF) is exactly the habit you need for `get_next_line` later in the core curriculum.
