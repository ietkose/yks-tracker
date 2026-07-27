# YKS Study Tracker

[![C Language](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.cppreference.com/w/c)
[![CLI](https://img.shields.io/badge/CLI-App-black.svg?style=for-the-badge&logo=gnu-bash&logoColor=white)](https://en.wikipedia.org/wiki/Command-line_interface)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)](LICENSE)

**[Visit Project Repository / Proje Deposu](https://github.com/ietkose/yks-tracker)**

﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌

## 🇬🇧 ENGLISH

> 📜 **Note:** This is my **first-ever open-source project** published on GitHub!

A lightweight command-line study tracking system engineered in **C** for students preparing for the Turkish Higher Education Institutions Exam (YKS). It enables students to record daily question solving counts (TYT/AYT) and study durations, providing dynamic statistical analysis and efficiency metrics.

---

### 📜 Key Features
* **Data Persistence**: Reads and writes daily study logs from/to a local structured file (`data.txt`).
* **Comprehensive Statistics**: Computes total solved question counts (categorized by TYT & AYT) and total/average study hours.
* **Efficiency Metrics**: Calculates *"Questions Solved per Hour"* to evaluate study session productivity.
* **Threshold Filtering**: Allows filtering logs based on specific question count thresholds.
* **Min/Max Analysis**: Automatically identifies the most and least productive study days.

---

### 📜 Tech Stack & Concepts
* **Language:** C (C99 / C11)
* **Compiler:** GCC / Clang / MSVC
* **Core Concepts:** File I/O (`fopen`, `fscanf`, `fprintf`), Structs, Dynamic/Static Arrays, Modular Control Flow

---

### 📜 Installation & Usage

#### 1. Clone the Repository
```bash
git clone [https://github.com/ietkose/yks-tracker.git](https://github.com/ietkose/yks-tracker.git)
cd yks-tracker
```

#### 2. Compile with GCC
```bash
gcc main.c -o tracker
```

#### 3. Run the Executable
> **Linux / macOS:**
```bash
./tracker
```

>**Windows:**
```bash
DOS
tracker.exe
```

#### File Structure & Data Format
The application expects/creates a data.txt file structured as follows:
```text
Plaintext
<TYT_Questions> <AYT_Questions> <Study_Hours>
Example: 120 80 5.5
```

---

### 📜 License
This project is licensed under the MIT License.

﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌

## 🇹🇷 TÜRKÇE
> 📜 **Not:** Bu proje, GitHub üzerinde yayınladığım **ilk açık kaynak projemdir**!

YKS (Yükseköğretim Kurumları Sınavı) hazırlık sürecindeki öğrenciler için C dili kullanılarak geliştirilmiş komut satırı tabanlı çalışma takip sistemi. Öğrencilerin günlük çözdükleri soru sayılarını (TYT/AYT) ve çalışma sürelerini kaydederek istatistiksel analizler ve verimlilik metrikleri sunar.

### 📜 Öne Çıkan Özellikler
* **Veri Kalıcılığı:** Günlük çalışma kayıtlarını yerel bir metin dosyasına (data.txt) kaydeder ve açılışta okur.
* **Detaylı İstatistikler:** Toplam çözülen TYT/AYT soru sayılarını ve ortalama çalışma sürelerini hesaplar.
* **Verimlilik Analizi:** Çalışma verimini ölçmek için "Saat Başına Düşen Soru Sayısı" analizi yapar.
* **Eşik Değer Filtreleme:** Belirli bir soru sayısının üzerine çıkılan verimli günleri filtreler.
* **En Az / En Çok Analizi:** En yüksek ve en düşük performans gösterilen günleri tespit eder.

### 📜 Kullanılan Teknolojiler ve Kavramlar
* **Dil:** C Dili
* **Derleyici:** GCC / Clang / MSVC
* **Temel Kavramlar:** Dosya İşlemleri (File I/O), Yapılar (Structs), Diziler (Arrays), Döngüler ve Modüler Yapı

### 📜 Kurulum ve Çalıştırma
#### 1. Depoyu Klonlayın
```bash
git clone [https://github.com/ietkose/yks-tracker.git](https://github.com/ietkose/yks-tracker.git)
cd yks-tracker
```

#### 2. GCC ile Derleyin
```bash
gcc main.c -o tracker
```

#### 3. Uygulamayı Başlatın
> **Linux / macOS:**
```bash
./tracker
```

> **Windows:**
```bash
DOS
tracker.exe
```

---

### 📜 Lisans
Bu proje MIT lisansı altında lisanslanmıştır.
