# push_swap
push_swap school 42

## Useful source

https://github.com/izenynn/push_swap_tester

    ./tester.sh .. -rn 10 0 99 -b

    cd push_swap_tester/ &&  ./tester.sh .. -rn 50 0 100 100 -b && cd .. 

-ro [RANGE START] [RANGE END] [QUANTITY]

    cd push_swap_tester/ &&  ./tester.sh .. -ro 0 100 5 && cd ..

Implementation of push-swap (42-school project) on python with GUI:
https://github.com/elijahkash/push_swap_gui
    python3 -m push_swap_gui

## Use checker 
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

## Scenario in push_to_a

* Scenario 1: rb, rra
* Scenario 2: rrb, ra
* Scenario 3: rb ra (with rr)
* Scenario 4: rrb rra (with rrr)

## Check_sort in push_to_b
1. min < med < max (sorted)
2. min < max < med (rra, rra, sa)
3. med < min < max (rra, sa)
4. med < max < min (ra, ra)
5. max < min < med (ra)
6. max < med < min (sa)

## Flags for rr, rrr and ss
* 'a', 'b' - for steak a and b respectively
* '0' - for ft_ra_rb (rr) and for ft_rra_rrb (rrr)
* 'c' - for checker