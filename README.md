# Linux-Process-Viewer 🚀
![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white) ![Qt](https://img.shields.io/badge/Qt-%23217346.svg?style=for-the-badge&logo=Qt&logoColor=white) ![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)

Este projeto é uma aplicação simples que usa C++ e Qt para visualizar e gerenciar processos do sistema operacional Linux. Ele foi criado com o objetivo de aprender e demonstrar minha habilidade em trabalhar com Qt, C++, multithreading e gerenciamento de processos.

## Funcionalidades 🎯
- **Visualização de Processos**: A interface gráfica exibe uma lista dos processos em execução no sistema.
- **Exibição em Tempo Real**: A aplicação utiliza threads para buscar e atualizar as informações dos processos sem travar a interface gráfica.
- **Interface grafica**: Desenvolvida com **Qt** para um interface grafica.

## Tecnologias Utilizadas 🛠️
- **C++**: A linguagem principal utilizada para o desenvolvimento da aplicação.
- **Qt**: Usado para a criação da interface gráfica (UI) e gerenciamento de eventos.
- **Multithreading (QThread)**: Para garantir que a atualização dos processos seja feita sem bloquear a interface gráfica.
- **Qt Creator**: Para desenvolvimento da interface e integração com o código.

## Como Rodar o Projeto 🚗
### Passos para Executar

1. **Clone o repositório**:
   ```bash
   git clone git@github.com:LuizFelipeOliver/Linux-Process-Viewer.git
   cd Linux-Process-Viewer
   ```
2. **Crie e entre na pasta de build**:
   ```bash
   mkdir build
   cd build
   ```
3. **Gere os arquivos de compilação com CMake**:
   ```bash
   cmake ..
   ```
4. **Compile o projeto**:
   ```bash
   make
   ```
5. **Execute a aplicação**:
   ```bash
   ./Linux_Process
   ```
## Como Funciona ⚙️
A aplicação faz uso de uma thread dedicada para buscar informações sobre os processos do sistema sem travar a interface gráfica. O ProcessManager é responsável por buscar periodicamente as informações dos processos, e a UI exibe essas informações em tempo real.

## Interface Gráfica 🖼️
A interface foi construída com Qt Widgets. Ela exibe os processos em uma tabela e é atualizada automaticamente conforme os dados são recebidos pelo ProcessManager.
