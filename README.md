Special-Checkers
================

Extended checkers game project for CSE240 at ASU

---------------------------
This is an extended version of the classic game Checkers.  There are three players on a 9 x 9 board and each player has a 'special' ability which may be used once per checker piece per game.

Red checkers have a sheild which protects them from being killed the first time they are jumped.
Black checkers have a self-destruct which has a 50/50 chance of also killing the opponent when the black checker gets jumped.
Green checkers have the ability to duplicate themselves (on non-jump moves).

---------------------------
The individual checker color-pieces inheret common functions from the CPiece base class.  The pieces are put into a linked-list formed by the CheckerList class, which is implemented through the CheckerBoard class.  CheckerBoard also provides the logic for printing the board, checking the legality of a move, and making the move.  The Game class implements the game loop, checking for wins/ties and passing user input to the board.
