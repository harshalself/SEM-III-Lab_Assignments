% NAME : HARSHAL PATIL
% ROLL NO : 44 

% Facts describing parent relationships
parent(john, ann).
parent(john, mary).
parent(jane, ann).
parent(jane, mary).

% Facts describing gender relationships
male(john).
female(ann).
female(jane).
female(mary).

% Predicate to check if X is Y's half-sister
half_sister(X, Y) :-
    parent(Z, X),        % Z is a parent of X
    parent(Z, Y),        % Z is also a parent of Y
    X \= Y,              % X and Y are different individuals
    \+ full_sister(X, Y), % X is not Y's full sister
    different_parent(X, Y). % X and Y have different parents

% Predicate to check if X and Y have different parents
different_parent(X, Y) :-
    parent(PX, X),
    parent(PY, Y),
    PX \= PY.

% Predicate to check if X is Y's full sister
full_sister(X, Y) :-
    female(X),
    parent(Z, X),
    parent(Z, Y),
    X \= Y.


%OUTPUT
% Query: Is Ann a half-sister of Mary?
?- half_sister(ann, mary).
% Result: Yes, it is true.

% Query: Is John a half-sister of Mary?
?- half_sister(john, mary).
% Result: No, it is false.2