# Object-Oriented Tennis Starter

This starter is intentionally incomplete. `Game`, `GameScore`, `PointScore`,
and the diagnostic `main` form a completed vertical slice. Build and run that
slice before implementing the remaining classes.

## Intended abstract-class exercise

`TieBreakerScore` deliberately does not override the pure virtual functions in
`Score`, so it begins as an abstract class. Part of the assignment is to decide
which overrides it needs, declare them, and define them.

## Diagnostic output

The starter's `print` messages show which score implementation is executing.
They are development traces. Adapt or disable them when producing the final
match transcript required by the assignment.

## Student completion checklist

Search the source for `TODO`. The work includes:

- completing `TieBreakerScore` so it is no longer abstract;
- implementing tie-break play and its service order;
- implementing set scoring and set play;
- implementing match scoring and match play; and
- replacing the one-game diagnostic driver with the complete match driver.

## Raw-pointer ownership rules

This project intentionally does not use smart pointers.

- `Competition` and `Score` do not own their `Player` pointers.
- Every `Competition::play` function returns a dynamically allocated `Score`;
  ownership transfers to the caller.
- `SetScore::addTieScore` takes ownership of the supplied score.
- `MatchScore::addSetScore` takes ownership of the supplied score.
- A score not transferred to another owner must be deleted by its caller.
- The virtual destructors in `Competition` and `Score` make deletion through a
  base pointer safe.

Do not use `reinterpret_cast`. The base-class interfaces are sufficient for
playing, recording, printing, and deleting scores polymorphically.

## Build and run

```console
make
./tennis.x
```

The starter reads the same seed and service probabilities as the function-based
program, then performs the diagnostic one-game run.
