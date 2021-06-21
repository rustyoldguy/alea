# alea
alea is an encryption program. It works on the basis of a transposition on the bit level Transposition
is the mixing up of the parts, the bits of a file. You have the choice from 64 bit up to 
131072 bit(factorials). Take for examplethe name "Fiedel Castro" you could change the order of the name "Friedel Tosac" from it
just by changing the sequence of letters. Likewise, you can only use individual components of a text.

This is called an anagram. More precisely, it is a permutation. Such a simple
Procedure is of course completely useless in todays world of powerful computers.
On closer inspection, however, another application can be found. The letters of the message
which are transmitted by a computer consist only of a sequence of zeros and ones,
the binary number system. The basis for this number system was made by the German mathematician
Gottfried Wilhelm Leibnitz (1646-1716) created. To make the matter more understandable, it is
it is more advantageous to have knowledge of the functionality of a DOS operating system based word processor
to provide work. In the days of MS-DOS, the components of a text are individual bytes. A
Byte, also known as char, consists of 8 bits which are nothing more than a sequence of zeros and
Represents ones. Simply put, these characters are a sequence of switching states of individual bits
within a byte. These &quot;zeros and ones&quot; form the components of an electronic message.
The &quot;conventional&quot; letter alphabet of a DOS computer consists of 256 characters from No. 0 to No. 255,
the so-called ASCII characters. Because originally only the so-called
named ASCII character set of characters from 0 to 127 used. This is always the same in DOS mode.
Changed, so the respective country, or USA, France, Germany etc. is adapted only the
extended character set (from 128 to 255). The characters from 0 to 31 form the invisible control
character of a conventional MS-DOS text.

Let us now consider the following:
For example, the letter "u"; has a decimal value of 117.
but as a binary number: 0IIIOIOI
The total number of all existing elements is 8. There are only 2 groups
of elements present, ones and zeros.
The group size of the ones is 5, that of the zeros is 3.
Or another example for a better understanding:

Task:
3 pears and 5 apples are to be displayed in a row.
How many options are there?
It doesn't matter if the order
Pear 1, Pear2, Apple1, Pear 3, Apple 2, Apple5, Apple 4, Apple 3
or
Pear 2, Pear3, Apple2, Pear 1, Apple 1, Apple3, Apple 4, Apple 5
reads.
In any case, only if you have at least 2 identical blocks when encrypting. Otherwise there are problems then
it doesn*t matter anymore, because otherwise 8 applies !. Which would result in 40320 possibilities. Always come in an emergency
two identical places before, that cannot be avoided.

See also: Formula for permutations with multiple occurrences of the same elements.

Another example:
We have half a byte, a so-called nibble, in front of us. This includes two ones and two zeros.
What is the possible number of combinations?

Possible combinations:
0011 (original state)
1100
0110
1001
1010
0101

One could also come up with the crazy idea and with one byte as simple encryption every second one
Extract bit to encrypt it:

Byte unencrypted: 11001010
As a first step, every second bit is extracted: 11001010
These bits are put together to form the first nibble: 1000
As a third step, every first bit is extracted: 11001010
These bits are combined to form the second nibble: 1011
Then the two nibbles are combined again into one bit: 10001011
A subsequent inversion would also be possible: 01110100
A shift to the left is also possible: 11101000
The mathematician Leonard Eulers has for such
 
Permutations with multiple occurrences of individual elements
developed a mathematical formula.

Combinations with two elements
There are only two elements (a and b) that appear multiple times within the group. The following must be applied to the
Calculating the number of possible permutations must be observed:

1 Total number of elements (class size, i.e. all ones and zeros)
2 group size of the elements (group size, the number of ones and zeros considered separately)

then: n = {(a + b)! / (a! * b!)}

But alea has up to (a+b) = 131072
The maximum number of possibile key-files are 131072!(1x2x3x4x5.....131072)

To representatives of state organs who read these lines, the following should be said:
In the Middle Ages there was the Italian politician and historian Niccolò Machiavelli (* 03.05.1469 to +22.06.1527).
One of his works is called Il Principe (The Prince). In section number XXIII (23) "Quomodo adulatores sint Fugiendi";
(How to avoid flatterers) it says among other things:

“If a prince, who is not himself clever, consults with several people, he will never receive advice that is the same,
and he himself will not be able to reconcile you; each of his advisors will think of his own advantage, and the prince
will neither correct nor see through you. ";

In summary this means:
“Good advice, from whomever it comes from, necessarily arises from the princes prudence, and not the princes prudence from good advice.”
To speak to Machiavelli.

You also have to be able to evaluate information; mere hoarding doesn’t help. Hoarding information that cannot be evaluated is like attempting to
hoard foreign-language literature without understanding this language and at the same time wanting to learn it, in the hope of being able to learn
these languages without making any effort. Powers that themselves information from The Code Key could look like this: Collecting others in order
to control others and not wanting to be controlled remind me of a word of Christ from the Gospel of Thomas:

Jesus said:
Woe to you, the Pharisees, for you are like a dog lying on the cattle feeding trough, because it neither eats (itself) nor lets the cattle eat.
It does not depend on the amount of information hoarded, according to the motto “The main thing is, a lot, the right one will be there somewhere”.
Excessive hoarding of information suggests insufficient (if any) skills and willingness to evaluate it correctly. You have to collect information
with which you can do something. It doesn’t matter to know everything. Just about where that right knowledge can be found.



A little user manual is also a part of this files, in englisch and in german.
