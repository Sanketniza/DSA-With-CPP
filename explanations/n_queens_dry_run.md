# N-Queens Algorithm Dry Run (n=4)

Let's trace through the execution of the N-Queens algorithm for n=4. We'll follow the recursive calls and backtracking steps to understand how solutions are found.

## Initial Setup

```
n = 4
board = [
    [0, 0, 0, 0],
    [0, 0, 0, 0],
    [0, 0, 0, 0],
    [0, 0, 0, 0]
]
ans = [] (empty vector to store solutions)
```

## First Call: solve(0, board, ans, 4)

We start with column 0 and try placing a queen in each row of this column.

### Try row=0, col=0:
- Check if (0,0) is safe: Yes (board is empty)
- Place queen: board[0][0] = 1
```
board = [
    [1, 0, 0, 0],
    [0, 0, 0, 0],
    [0, 0, 0, 0],
    [0, 0, 0, 0]
]
```
- Recursive call: solve(1, board, ans, 4)

#### In solve(1, board, ans, 4):
- Try row=0, col=1:
  - Check if (0,1) is safe: No (attacked by queen at (0,0))
- Try row=1, col=1:
  - Check if (1,1) is safe: No (attacked diagonally by queen at (0,0))
- Try row=2, col=1:
  - Check if (2,1) is safe: Yes
  - Place queen: board[2][1] = 1
  ```
  board = [
      [1, 0, 0, 0],
      [0, 0, 0, 0],
      [0, 1, 0, 0],
      [0, 0, 0, 0]
  ]
  ```
  - Recursive call: solve(2, board, ans, 4)

##### In solve(2, board, ans, 4):
- Try each row in column 2...
- At row=0, col=2: Not safe
- At row=1, col=2: Not safe
- At row=3, col=2: Not safe
- No safe position found in column 2
- Backtrack: board[2][1] = 0
```
board = [
    [1, 0, 0, 0],
    [0, 0, 0, 0],
    [0, 0, 0, 0],
    [0, 0, 0, 0]
]
```

- Try row=3, col=1:
  - Check if (3,1) is safe: Yes
  - Place queen: board[3][1] = 1
  ```
  board = [
      [1, 0, 0, 0],
      [0, 0, 0, 0],
      [0, 0, 0, 0],
      [0, 1, 0, 0]
  ]
  ```
  - Recursive call: solve(2, board, ans, 4)

##### In solve(2, board, ans, 4):
- Try each row in column 2...
- At row=1, col=2: Yes, it's safe
- Place queen: board[1][2] = 1
```
board = [
    [1, 0, 0, 0],
    [0, 0, 1, 0],
    [0, 0, 0, 0],
    [0, 1, 0, 0]
]
```
- Recursive call: solve(3, board, ans, 4)

###### In solve(3, board, ans, 4):
- Try each row in column 3...
- At row=2, col=3: Yes, it's safe
- Place queen: board[2][3] = 1
```
board = [
    [1, 0, 0, 0],
    [0, 0, 1, 0],
    [0, 0, 0, 1],
    [0, 1, 0, 0]
]
```
- Recursive call: solve(4, board, ans, 4)

####### In solve(4, board, ans, 4):
- Base case reached (col == n)
- Add solution to ans:
```
ans = [
    [1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0]
]
```
- Return to previous call

###### Back to solve(3, board, ans, 4):
- Backtrack: board[2][3] = 0
```
board = [
    [1, 0, 0, 0],
    [0, 0, 1, 0],
    [0, 0, 0, 0],
    [0, 1, 0, 0]
]
```
- No more rows to try in column 3
- Return to previous call

##### Back to solve(2, board, ans, 4):
- Backtrack: board[1][2] = 0
```
board = [
    [1, 0, 0, 0],
    [0, 0, 0, 0],
    [0, 0, 0, 0],
    [0, 1, 0, 0]
]
```
- No more safe positions in column 2
- Return to previous call

#### Back to solve(1, board, ans, 4):
- Backtrack: board[3][1] = 0
```
board = [
    [1, 0, 0, 0],
    [0, 0, 0, 0],
    [0, 0, 0, 0],
    [0, 0, 0, 0]
]
```
- No more rows to try in column 1
- Return to previous call

### Back to solve(0, board, ans, 4):
- Backtrack: board[0][0] = 0
```
board = [
    [0, 0, 0, 0],
    [0, 0, 0, 0],
    [0, 0, 0, 0],
    [0, 0, 0, 0]
]
```

### Try row=1, col=0:
- Check if (1,0) is safe: Yes
- Place queen: board[1][0] = 1
```
board = [
    [0, 0, 0, 0],
    [1, 0, 0, 0],
    [0, 0, 0, 0],
    [0, 0, 0, 0]
]
```
- Recursive call: solve(1, board, ans, 4)

The algorithm continues this pattern of trying placements, making recursive calls, and backtracking when necessary. It will find all valid solutions where no queen can attack another.

## Final Result

For n=4, the algorithm will find 2 solutions:
1. Queens at positions: (1,0), (3,1), (0,2), (2,3)
2. Queens at positions: (2,0), (0,1), (3,2), (1,3)

These solutions represent the two ways to place 4 queens on a 4×4 board where no queen can attack another.

## Key Observations

1. The algorithm tries each row in the current column before moving to the next column
2. It uses backtracking to undo placements that don't lead to solutions
3. The `isSafe()` function checks three directions (left, upper-left diagonal, lower-left diagonal)
4. The board uses [row][col] indexing, where board[i][j] = 1 means a queen is placed at row i, column j