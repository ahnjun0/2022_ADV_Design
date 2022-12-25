import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
from sklearn.linear_model import LinearRegression


data = pd.read_csv("2022_ADV_Design\Main\Regression\measurement.csv")
# data.head()

plt.figure(figsize=(8,8))
sns.scatterplot(y='Cervical spine Angle', x='Resistance value', data=data)

x = data['Resistance value'].values.reshape(-1,1)
y = data['Cervical spine Angle']

fit = LinearRegression().fit(x,y)
intercept = fit.intercept_ ## 절편
fx = fit.coef_ ## 기울기
r2 = fit.score(x,y) ## R_square, 결정계수

y_predict = fit.predict(x.reshape((-1,1))) 
plt.plot(x, y_predict, color='red')

plt.title('Correlation between Resistance value and Angle of Flex Sensor')
plt.xlabel('Cervical spine Angle')
plt.ylabel('Resistance value')
plt.grid(True)

print("R² = {}".format(r2))
print("y = {}x {}".format(fx, intercept))
plt.show()