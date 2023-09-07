import os
import matplotlib.pyplot as plt
import pandas as pd

for filename in os.listdir('./out'):
    plt.figure()

    filepath = os.path.join('./out', filename)
    print(filepath)

    data = pd.read_csv(filepath)
    
    algorithms = data.Algorithm.unique()

    data_algorithm = {}
    for algorithm in algorithms:
        df = data[data.Algorithm == algorithm].drop(columns='Algorithm')
        df = df.sort_values('N')
        data_algorithm[algorithm] = df

        plt.plot(df.N, df.TimeTaken, label=algorithm)

    plt.xlabel('Array Length')
    plt.ylabel('Time (micro-seconds)')
    plt.title(filename)
    plt.legend()
    plt.show()