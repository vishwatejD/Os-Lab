#!/bin/bash

# Read basic salary
read -p "Enter Basic Salary: " basic

# Read TA (Travel Allowance)
read -p "Enter TA: " ta

# Calculate 10% of Basic Salary
bonus=$(echo "$basic * 0.10" | bc)

# Calculate Gross Salary: GS = Basic + TA + 10% of Basic
gross_salary=$(echo "$basic + $ta + $bonus" | bc)

# Display Gross Salary
echo "Gross Salary: $gross_salary"
