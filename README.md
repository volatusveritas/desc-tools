# Desclang

The term "Desclang" is a shorthand for "Description Language". This simple
syntax concept aims to keep a balance between clarity and completeness. A
Desclang file, by convention, carries the extension `.desc` as to differentiate
it from other filetypes. A file carrying the extension `.desc` is called a
"descfile".

## Descfile
A Descfile contains a sequence of plaintext, that may or may not be divided
into Sections. The plaintext within each section (or along the entire file,
given the file has no sections) may or may not be populated with Definitions. A
Descfile may also containt Comments amidst plaintext.

## Sections
A Section is any amount of plaintext or Definitions between a Section Header
and the next Section Header or between a Section Header and the end of the
file.

### Section Header
A Section Header is the keyword "Section" (case sensitive) followed by a
space and an optional Section Numerator and a space, followed by the Section
Identifier.

#### Section Numerator
A Section Numerator is any sequence of digits, possibly separated by dots to
denote subsections, and optionally suffixed by an extra dot not followed by any
digit. Examples: `1.0.2.`; `4.2.`; `3`; `4.2`; `5.1`.

#### Section Identifier
A Section Identifier is any sequence of plaintext that follows the "Section"
keyword or the Section Numerator, and ends when two consecutive line breaks are
found (e.g. an empty line after the text).

#### Section Header Examples
Presume each of the following examples is followed by two occurences of a line
break (e.g. are followed by an empty line). Following are some examples.

- `Section 3.1. Goblins and Their Sacred Spears`;
- `Section Crafting boots using pickaxes`;
- `Section 4.2.1. Dog Caretaking Details`;
- `Section 2 What Follows the First`;

## Definitions
A Definition is a combination of a Definition Identifier and a Definition
Description. There are three types of Definitions. The first is a Simple
Definition (or inline definition), the second is a Compound Definition (or
multidot definition), and the third is a Complete Definition (or complex
definition).

### Definition Identifier
A Definition Identifier is any plaintext surrounded by brackets (`[` and `]`).
The character that immediately follows the closing bracket determintes the type
of Definition. If it is a space, the Definition is a Simple Definition; if it
is a colon, the Definition is a Compound Definition; and if it is a question
mark followed by a line break, the Definition is a Complete Definition.
Following are some examples.

- `[Boiled Egg]` (Simple Definition);
- `[Pink Broccoli]:` (Compound Definition);
- `[Encyclopedia]?` (Complete Definition);

### Definition Description
A Definition Description is any plaintext from the Definition Identifier to its
end. For a Simple Definition, its end is the first occurence of a dot, an
exclamation mark or a question mark. For a Compound Definition, its end is at
any dot, exclamation mark or question mark that preceedes an occurence of `<e`.
For a Complete Definition, its end is at the last line preceeding a line that
only contains `<definition end>`. For the Simple Definition, any text
preceeding the Definition Identifier until any occurence of an ending (a dot, a
question mark, an exclamation mark, an occurence of `<e` or `<definition
end>`).

## Comments
A Comment is any amount of plaintext simply used for source annotation. It is
mostly, or entirely, discarded once the source file is processed into something
else. By themselves, comments have no special meaning or use inside a Descfile.
However, once you use a conversion tool (e.g. converting from Descfile to
Markdown or HTML), these comments are ignored as part of the source file (that
is to say they will not be present on the final version of the file). Comments
are reserved because in the future there will be Descfile use for Comments
(with the addition or Metacomments). There are two types of comments; the first
type is a Simple Comment (or inline comment), and the second is a Compound
Comment (or multiline comment).

### Simple Comments
A Simple Comment is any amount of plaintext following `c>` until the end of the
line (the line break is not part of the Comment).

### Compound Comments
A Compound Comment is any amount of plaintext following `c:s>` and preceeding
`<c:e`. The start and end markers are not part of the Comment.

## Complete Definition Details
To be considered a Complete Definition, the Definition Identifier must be at
the start of the line, followed by a question mark (`?`) and a line break.
Then, everything from the next line forward is considered part of the
Definition, until a single line containing `<definition end>` (and nothing
else) is found. Complete Definitions are special because they can contain other
Definitions inside them (Subdefinitions).

### Subdefinitions
Subdefinitions (or child definitions) are Definitions that appear inside a
Complete Definition. They work the same way Simple and Compound Definitions do,
with one exception: their Definition Identifier must be preceeded by `s>` (the
Subdefinition Marker).

### Complete Definition Example

```Desclang
[Combat]
A Combat is a sequence of Rounds. A s>[Round] is any a collection of Turns. A
s>[Turn] is a sequence of Actions performed by a Character. An s>[Action] can
be a Functional Action, a Movement Action or a Special Action. Following are
the definitions of each action type.
s>[Functional Action]: any action that requires significant time. It may be the
use of a skill, the usage of a mechanism, an attack, etc.<e
s>[Movement Action]: any action that is related to movement or interaction. It
may be moving from a place in the battlefield to another, picking up an item or
interacting with a simple mechaniscm (a button, a lever, etc.).<e
<definition end>
```
