# Speller

A basic spell checker.

It requires a dictionary in the form of a text file as an input.

## Usage

```bash
cd speller
make
./speller [dictionary] file
```

---

## Working

- The function's for loop works as follows: while c is not equal to the EOF, do the following: set to c the integer value of the character as returned by fgetc.

- Next check if the returned character is an alphabet or is an apostrophe, if it is: append the character to the word and increment the index; also if there are alphabetical strings too long to be words, ignore them and set the index to zero.

- else if c is a number, ignore that word.

- if c is not a letter, a digit, a number or an apostrophe, we must have a new word, so terminate the word with a '\0', update the words counter, check if the word is in the dictionary and get the time required to do so.

- Update the time benchmark. If the word isn't in the dictionary, print the word and update the misspellings counter. Set the index to zero and again set c to the next character in the file.
