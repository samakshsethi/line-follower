# line-follower
Line follower robot

Execution procedure:
1. The motors will be turned on when the robot is aligned with the line
2. If one of the IR sensors comes over black line, the opposite wheel will turn off, shifting the robot's alignment in the direction of the line 
3. If both IR sensors are over the line (usually for sharp corners), both wheels are moved for 20ms to fix it and then, the loops are continued as is
