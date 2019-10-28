m = 1 (1 kinds of resources)
n = 3 (3 customer)


at the beginning
Available = [3]
Allocated = [
  [0],
  [0],
  [0]
]



Available = [1]
Max = [
  [2],
  [3],
  [1]
]
Allocated = [
  [0],
  [2],
  [0]
]
Need = [
  [2],
  [1],
  [1]
]


Start Safety now
// step 1
Work = Available = [1]
Finish = [f, f, f]

// step 2
i = 0
Finish[i] = f
Need[i] = [2]
Work = [1]

i = 1
Finish[i] = f
Need[i] = [1]
Work = [1]

// step 3
i = 1
work = work + allocation[i]
work = [1] + [2]
work = [3]
finish = [f, t, f]

// step 2
i = 0
finish[0] = f
need[0] = [2]
work = [3]

// step 3
i = 0
work = work + allocation[0]
work = [1] + [2]
work = [3]
finish = [t, t, f]




request fails due to unsafe state
need = [
  [3, 3],
  [1, 1]
]
available = [2, 2]
 ===
request for 0 = [2, 2]
 ===
available = [0, 0]
need = [
  [1, 1],
  [1, 1]
]
