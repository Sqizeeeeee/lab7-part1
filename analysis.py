import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import os
import numpy as np

# Создаем папку для графиков
os.makedirs('graphs', exist_ok=True)

# Русские шрифты для графиков
plt.rcParams['font.family'] = 'DejaVu Sans'

def analyze_sorting():
    """Анализ результатов сортировок"""
    print("=== АНАЛИЗ АЛГОРИТМОВ СОРТИРОВКИ ===")
    df = pd.read_csv('data/sorting_results.csv')
    print("Данные:")
    print(df.head())
    
    # График времени выполнения
    plt.figure(figsize=(12, 8))
    
    colors = {'selection': 'red', 'bubble': 'blue', 'merge': 'green'}
    markers = {'random': 'o', 'sorted': 's', 'reversed': '^'}
    
    for algo in df['algorithm'].unique():
        for case in df['case_type'].unique():
            subset = df[(df['algorithm'] == algo) & (df['case_type'] == case)]
            if not subset.empty:
                plt.plot(subset['data_size'], subset['time_micros'], 
                        marker=markers[case], color=colors[algo],
                        linewidth=2, label=f'{algo} ({case})')
    
    plt.xlabel('Размер массива')
    plt.ylabel('Время (микросекунды)')
    plt.title('Сравнение алгоритмов сортировки')
    plt.legend(bbox_to_anchor=(1.05, 1), loc='upper left')
    plt.grid(True, alpha=0.3)
    plt.tight_layout()
    plt.savefig('graphs/sorting_comparison.png', dpi=300, bbox_inches='tight')
    plt.close()
    
    # Анализ эффективности
    print("\nСреднее время выполнения (микросекунды):")
    summary = df.groupby(['algorithm', 'case_type'])['time_micros'].mean().round(2)
    print(summary)
    
    # Сравнение алгоритмов на случайных данных
    random_data = df[df['case_type'] == 'random']
    print("\nСравнение на случайных данных:")
    for algo in random_data['algorithm'].unique():
        algo_data = random_data[random_data['algorithm'] == algo]
        avg_time = algo_data['time_micros'].mean()
        print(f"  {algo}: {avg_time:.2f} мкс")

def analyze_search():
    """Анализ результатов поиска"""
    print("\n=== АНАЛИЗ АЛГОРИТМОВ ПОИСКА ===")
    df = pd.read_csv('data/search_results.csv')
    print("Данные:")
    print(df.head())
    
    # График времени выполнения
    plt.figure(figsize=(12, 8))
    
    for algo in df['algorithm'].unique():
        for case in ['best', 'average', 'worst']:
            subset = df[(df['algorithm'] == algo) & (df['case_type'] == case)]
            if not subset.empty:
                plt.plot(subset['data_size'], subset['time_micros'], 
                        marker='o', linewidth=2, label=f'{algo} ({case})')
    
    plt.xlabel('Размер массива')
    plt.ylabel('Время (микросекунды)')
    plt.title('Сравнение алгоритмов поиска')
    plt.legend(bbox_to_anchor=(1.05, 1), loc='upper left')
    plt.grid(True, alpha=0.3)
    plt.tight_layout()
    plt.savefig('graphs/search_comparison.png', dpi=300, bbox_inches='tight')
    plt.close()
    
    # Анализ эффективности
    print("\nЭффективность поиска:")
    efficiency = df.groupby(['algorithm', 'case_type'])['time_micros'].mean().round(2)
    print(efficiency)
    
    # Сравнение sequential vs binary
    print("\nSequential vs Binary search (среднее время):")
    seq_avg = df[df['algorithm'] == 'sequential']['time_micros'].mean()
    bin_avg = df[df['algorithm'] == 'binary']['time_micros'].mean()
    print(f"  Sequential: {seq_avg:.2f} мкс")
    print(f"  Binary: {bin_avg:.2f} мкс")
    print(f"  Binary быстрее в {seq_avg/bin_avg:.1f} раз")

def analyze_geometry():
    """Анализ поиска ближайших точек"""
    print("\n=== АНАЛИЗ ПОИСКА БЛИЖАЙШИХ ТОЧЕК ===")
    df = pd.read_csv('data/geometry_results.csv')
    print("Данные:")
    print(df.head())
    
    # Время выполнения
    plt.figure(figsize=(10, 6))
    
    for algo in df['algorithm'].unique():
        subset = df[df['algorithm'] == algo]
        plt.plot(subset['points_count'], subset['time_micros'], 
                marker='o', linewidth=3, label=algo)
    
    plt.xlabel('Количество точек')
    plt.ylabel('Время (микросекунды)')
    plt.title('Поиск ближайших точек - время выполнения')
    plt.legend()
    plt.grid(True, alpha=0.3)
    plt.tight_layout()
    plt.savefig('graphs/geometry_time.png', dpi=300, bbox_inches='tight')
    plt.close()
    
    # Анализ роста времени
    print("\nРост времени выполнения:")
    for algo in df['algorithm'].unique():
        subset = df[df['algorithm'] == algo]
        times = subset['time_micros'].values
        counts = subset['points_count'].values
        
        if len(times) > 1:
            growth = times[-1] / times[0]
            print(f"  {algo}: с {counts[0]} до {counts[-1]} точек - рост в {growth:.1f} раз")

def analyze_complexity():
    """Анализ вычислительной сложности"""
    print("\n=== ТЕОРЕТИЧЕСКАЯ СЛОЖНОСТЬ ===")
    
    complexities = {
        'selection_sort': 'O(n²) - квадратичная',
        'bubble_sort': 'O(n²) - квадратичная', 
        'merge_sort': 'O(n log n) - линейно-логарифмическая',
        'sequential_search': 'O(n) - линейная',
        'binary_search': 'O(log n) - логарифмическая',
        'brute_force': 'O(n²) - квадратичная'
    }
    
    for algo, complexity in complexities.items():
        print(f"  {algo:20} {complexity}")

def main():
    """Основная функция анализа"""
    print("АНАЛИЗ РЕЗУЛЬТАТОВ ЭКСПЕРИМЕНТОВ")
    print("=" * 50)
    
    analyze_sorting()
    analyze_search() 
    analyze_geometry()
    analyze_complexity()
    
    print("\n" + "=" * 50)
    print("Графики сохранены в папку graphs/")
    print("Анализ завершен!")

if __name__ == "__main__":
    main()