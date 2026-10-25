# The following code was made in a Jupyter notebook
# To see the original notebook: https://gist.github.com/cararm4073/69866ee71b51ff26adaf4d53fca3611a

import pymysql
import matplotlib.pyplot as plt

# %%
#Please note that this is a testing db, no real info is contained in here
tec_db = pymysql.connect(host='127.0.0.1', user='root', password='', port=3307, database='tecinfo')
mycursor = tec_db.cursor()

# %% [markdown]
# # First query
# Get the amount of students that either have a schollarship (1) or not (1), and show the total of students in each group

# %%
mycursor.execute('SELECT CASE WHEN EsBecado = 1 THEN "Has scholarship" ELSE "Doesn\'t have scholarship" END AS status, COUNT(*) FROM Estudiantes GROUP BY EsBecado')
schollarship = mycursor.fetchall()

# %%
status = []
total = []

for i in schollarship:
    status.append(i[0])
    total.append(i[1])

# %%
print("Status = ", status)
print("Total = ", total)

# %%
plt.figure(figsize=(5, 8))
plt.pie(total, labels=total, autopct="%1.1f%%", startangle=90, colors=["coral", "lightgreen"])

plt.title("Proportion of students with schollarships")
plt.legend(status)
plt.show()

# %% [markdown]
# # Second query
# Top 5 students with reports, ordered by such reports, and then alplhabetically by their name

# %%
mycursor.execute("SELECT CONCAT(Nombre, ' ', Apellido), Reportes FROM Estudiantes ORDER BY Reportes DESC, Nombre ASC LIMIT 5")
topReports = mycursor.fetchall()

# %%
namesReports = []
totalReports = []

# %%
for i in topReports:
    namesReports.append(i[0])
    totalReports.append(i[1])

# %%
print("Names: ", namesReports)
print("Reports: ", totalReports)

# %%
plt.figure(figsize=(8, 4))
plt.bar(namesReports, totalReports, color="orange")

plt.title("Top 5 students with reports")
plt.xlabel("Student's name")
plt.ylabel("Amount of reports")
plt.ylim(0,6.5)
plt.grid(axis="y")
plt.show()

# %% [markdown]
# Note: There are many students with 5 reports. Here, the first 5 ordered alphabetically by their name are shown

# %% [markdown]
# # Third query
# Total of new students per year

# %%
mycursor.execute("SELECT YEAR(FechaDeIngreso) AS Year, COUNT(*) FROM Estudiantes GROUP BY YEAR(FechaDeIngreso) ORDER BY Year ASC")
newStudents = mycursor.fetchall()

# %%
year = []
totalNewStudents = []

# %%
for i in newStudents:
    year.append(str(i[0]))
    totalNewStudents.append(i[1])

# %%
print("Years: ", year)
print("Total students: ", totalNewStudents  )

# %%
plt.figure(figsize=(8, 4))
plt.plot(year, totalNewStudents, marker="o")

plt.title("New students per year")
plt.xlabel("Year of admission")
plt.ylabel("Number of students")
plt.grid(True)
plt.show()

# %% [markdown]
# # Fourth query
# Group the performance of the students
# 
# * If the average of a student is above 9.0, grouped under Excellence
# 
# * If the average of a student is above 8.0, grouped under Great
# 
# * If the average of a student is above 7.0, grouped under Regular
# 
# * The rest of the students are grouped as Bad

# %%
mycursor.execute('SELECT CASE WHEN Promedio >= 9.0 THEN "Excellence" WHEN Promedio >= 8.0 THEN "Great" WHEN Promedio >= 7.0 THEN "Regular" ELSE "Bad" END AS Performance, COUNT(*) FROM Estudiantes GROUP BY Performance ORDER BY MIN(Promedio) DESC')
studentPerformance = mycursor.fetchall()

# %%
performance = []
totalPerformance = []

# %%
for i in studentPerformance:
    performance.append(i[0])
    totalPerformance.append(i[1])

# %%
print("Performance labels: ", performance)
print("Total per label: ", totalPerformance)

# %%
plt.figure(figsize=(8, 4))
plt.bar(performance, totalPerformance, color=["turquoise", "olive", "gold", "salmon"])

plt.title("Academic performance of the students")
plt.xlabel("Grade ranges")
plt.ylabel("Number of students")
plt.ylim(0, 65)
plt.grid(axis="y")
plt.show()

# %% [markdown]
# # Fifth query
# Calculate the average of the student's averages. grouping by the amount of reports

# %%
mycursor.execute("SELECT Reportes, ROUND(AVG(Promedio), 2) FROM Estudiantes GROUP BY Reportes ORDER BY Reportes ASC")
comparison = mycursor.fetchall()

# %%
numReports = []
average = []

# %%
for i in comparison:
    numReports.append(str(i[0]))
    average.append(float(i[1]))

# %%
print("Reports: ", numReports)
print("Averages: ", average)

# %%
plt.figure(figsize=(8, 5))
plt.bar(numReports, average, color="lightblue")

plt.title("Average grades by number of reports")
plt.xlabel("Number of reports")
plt.ylabel("Average grade")
plt.ylim(7.5, 8.5)
plt.grid(axis="y")
plt.show()

# %% [markdown]
# # Documentation
# The following documentation was used to complete this activity:
# 
# https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.pie.html
# 
# https://matplotlib.org/stable/users/explain/colors/colors.html#colors-def
