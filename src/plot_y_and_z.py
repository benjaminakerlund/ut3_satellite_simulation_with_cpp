import matplotlib.pyplot as plt
import pandas as pd

# Load CSV file (assuming it's named 'data.csv')
df = pd.read_csv("data.csv", header=None)

# Axes
y_angle = df[0]
z_angle = df[1]
time = range(len(df))

# Create subplots
fig, axs = plt.subplots(2, 1, figsize=(10, 8), sharex=True)

# Plot Y angle
axs[0].plot(time, y_angle, label="Y Angle", color="b", marker="o", linestyle="-")
axs[0].set_ylabel("Y Angle")
axs[0].set_title("Y and Z Angles Over Time")
axs[0].legend()
axs[0].grid()

# Plot Z angle
axs[1].plot(time, z_angle, label="Z Angle", color="r", marker="o", linestyle="-")
axs[1].set_xlabel("Time (s)")
axs[1].set_ylabel("Z Angle")
axs[1].legend()
axs[1].grid()

# Show plot
plt.tight_layout()
plt.show()