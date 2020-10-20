# Lab1
### Data structures (\*\*\* + \*)
List and heap realization of priority queue.

**Methods implemented(both list and heap realization):**
- peek
- next value
- add new element
- print

### Custom classes (\*\*\* + \*)
`Dice Class`:
Face numbers N = 2, 4, 6, 8, 12, 20.
Every face has its own probability of being dropped.

`DiceSet`:
A set of dices.

**Methods implemented:**
- count min and max sums
- count probabilities for all possible sums in set
- count expected value of set

**Operators overloaded:**
- << for `std::ostream` and `Dice`
- << for `std::ostream` and `DiceSet`
- relational operators for two sets (comparing expected values)