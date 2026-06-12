#The Jupyter Notebook file can be seen here: https://gist.github.com/cararm4073/15759fc0aa9fe9800cef40f840284399

import numpy as np
import matplotlib.pyplot as plt

#Ordinary Differential Equation system
def f(t, y):
    array = np.array([y[1], -2 * y[1] - y[0]])
    return array

#Second order Runge-Kutta method
def rungekutta_2(f, ti, yi, tf, h):
    t_values = np.arange(ti, tf + h, h)
    y_values = np.zeros((len(t_values), len(yi)))
    y_values[0] = yi

    for i in range(len(t_values) - 1):
        tn = t_values[i]
        yn = y_values[i]

        k1 = h * f(tn, yn)
        k2 = h * f(tn + h, yn + k1)

        y_values[i + 1] = yn + 0.5 * (k1 + k2)

    return t_values, y_values

#Fourth order Runge-Kutta method
def rungekutta_4(f, ti, yi, tf, h):
    t_values = np.arange(ti, tf + h, h)
    y_values = np.zeros((len(t_values), len(yi)))
    y_values[0] = yi

    for i in range(len(t_values) - 1):
        tn = t_values[i]
        yn = y_values[i]

        k1 = h * f(tn, yn)
        k2 = h * f(tn + h / 2, yn + k1 / 2)
        k3 = h * f(tn + h / 2, yn + k2 / 2)
        k4 = h * f(tn + h, yn + k3)

        y_values[i + 1] = yn + (1 / 6) * (k1 + 2 * k2 + 2 * k3 + k4)

    return t_values, y_values


#input verification
while True:
    try:
        ti = float(input("Enter a value for the initial time (ti): "))
        break
    except ValueError:
        print("Please enter a valid number.\n")

while True:
    try:
        pos_i = float(input("Enter a value for the initial position: "))
        break
    except ValueError:
        print("Please enter a valid number.\n")

while True:
    try:
        vel_i = float(input("Enter a value for the initial velocity: "))
        break
    except ValueError:
        print("Please enter a valid number.\n")

yi = np.array([pos_i, vel_i])

while True:
    try:
        tf = float(input("Enter a positive value for the final time (must be greater than ti): "))
        if tf <= ti:
            print(f"The final time ({tf}) cannot be less or equal to the initial one ({ti}).")
        else:
            break
    except ValueError:
        print("Please enter a valid number.\n")

while True:
    try:
        h = float(input("Enter a value greater than 0 for the step size: "))
        if h <= 0:
            print("Please enter a positive number.\n")
        else:
            break
    except ValueError:
        print("Please enter a valid number.\n")

#execution of runge kutta's method
t_rungek2, y_rungek2 = rungekutta_2(f, ti, yi, tf, h)
t_rungek4, y_rungek4 = rungekutta_4(f, ti, yi, tf, h)

#show the results
print("Runge Kutta second order")
print(f"  Final position:  {y_rungek2[-1, 0]:.6f}")
print(f"  Final velocity: {y_rungek2[-1, 1]:.6f}\n")

print("\nRunge Kutta fourth order")
print(f"  Final position:  {y_rungek4[-1, 0]:.6f}")
print(f"  Final velocity: {y_rungek4[-1, 1]:.6f}")



#graphs
plt.figure(figsize=(14, 5))

plt.subplot(1, 2, 1)
plt.plot(t_rungek2, y_rungek2[:, 0], label='Position - Runge Kutta 2nd order')
plt.plot(t_rungek4, y_rungek4[:, 0], label='Position - Runge Kutta 4th order')
plt.title('Position (y) vs Time (t)')
plt.xlabel('Time (t)')
plt.ylabel('Position (y[0])')
plt.grid(True)
plt.legend()

plt.subplot(1, 2, 2)
plt.plot(t_rungek2, y_rungek2[:, 1], label='Speed - Runge Kutta 2nd order')
plt.plot(t_rungek4, y_rungek4[:, 1], label='Speed - Runge Kutta 4th order')
plt.title('Speed (y[1]) vs Time (t)')
plt.xlabel('Time (t)')
plt.ylabel('Speed (y[1])')
plt.grid(True)
plt.legend()

plt.tight_layout()
plt.show()