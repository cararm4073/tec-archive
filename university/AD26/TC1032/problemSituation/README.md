## Credits

- TickQ. (2023a, November 11). *MARIE | Indirect Addressing & Subroutine* [Video]. YouTube.
  https://www.youtube.com/watch?v=kqZkMRH_U48
  (indirect addressing and subroutine structure used as the base)
- TickQ. (2023b, September 19). *MARIE | Jump, SkipCond and Loops* [Video]. YouTube.
  https://www.youtube.com/watch?v=zvxdEHPG5oc
  (count-down loop with Skipcond)

*Please note that these were used to understand the topics of class, and used as an important reference on building this version of the code.*

### Ideas from the videos
- The pointer-based storage with `StoreI`/`LoadI`
- The subroutine structure (`JnS` / `JumpI`)
- The `Skipcond` used for loops


### What we changed
Adapted the program to the sensor requirements:
- Replaced the condition in which if a value is 0, the program terminaes on both reading and printing
- 50 readings are stored even if a reading is 0
- Tested with 0-values in random places of the reading to assure correctness.