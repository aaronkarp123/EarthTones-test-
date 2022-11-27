## PolarCV

This is a module that generates control voltages that correspond to a point traveling along various polar equations.

<img width="270" alt="image" src="https://user-images.githubusercontent.com/8389851/204151257-8c59da77-bf39-4a3f-b88b-229fff34f771.png">

The red dot indicates the current position, which travels along the equation lines.

The left-most control knob corresponds to the speed at which the dot travels (the ΔΘ). That can be adjusted by rotating the knob, or be controlled directly from a control voltage using the input to its left. The "mult" button to the upper left of the speed dial modifies the speed by a fixed amount. This is either 0.5x, 1.0x, or 2.0x. 

The current equation (along with the speed multiplier) can be seen in the top bar. There are a total of four different equations, which can be switched using the ⮕ and ⬅ buttons. The equations all have two constants, A and B, which can be changed via the A and B knobs. Changing these values can create very different results, so I would encourage exploring different combinations of equations and constants.

There are three outputs:
- **r** is the radius of the current position (in polar coordinates)
- **x** is the horizontal component of the current position (in cartesian coordinates)
- **y** is the vertical component of the current position (in cartesian coordinates)
