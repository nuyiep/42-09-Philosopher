# 42-09-Philosopher

![Dining_philosophers_diagram](https://github.com/user-attachments/assets/82e71cd1-bd82-4a42-97d8-45b5fdf69424)


Eat, Sleep, Spaghetti, repeat. This project is about learning how threads work by precisely timing a group of philosophers on when to pick up forks and eat spaghetti without dying from hunger.

## Examples
- `./philo 1 800 200 200` - Philosopher 1 will die at 800
- `./philo 5 800 200 200` - No philosopher should die
- `./philo 5 800 200 200 7`- No philosopher should die and the simulation should stop when everyone has eaten at least 7 times
- `./philo 4 410 200 200` - No philosopher should die
- `./philo 4 310 200 100` - One philosopher should die
