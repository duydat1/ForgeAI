# ForgeAI

ForgeAI is a C++ code intelligence engine designed to analyze software projects and extract useful information from their source code.

The project is being developed incrementally, starting from a lightweight C++ static analysis engine and gradually evolving toward a larger code intelligence platform.

## Current Version

**v1.0.0 — Project Scanner & Basic Metrics**

## Current Features

ForgeAI v1 can:

- Accept a project path from the command line
- Recursively scan project directories
- Detect C++ source files
- Support:
    `.cpp`
    `.h`
    `.hpp`
- Ignore non-source files during analysis
- Analyze individual source files
- Calculate basic source-code metrics
- Aggregate metrics across the entire project
- Store metrics for individual files using `std::vector`

### Current Metrics

For each source file, ForgeAI currently calculates:

- Total lines
- Blank lines
- Comment lines
- Code lines

For the entire project, ForgeAI calculates:

- Total source files
- Total lines
- Total blank lines
- Total comment lines
- Total code lines


## Example

```text
ForgeAI
=======

Target:
D:\Projects\MyProject

Scanning project...

"D:\Projects\MyProject\main.cpp"
    Total lines:   120
    Blank lines:   20
    Comment lines: 15
    Code lines:    85

Project Statistics
------------------
    Source files:   1
    Total lines:    120
    Blank lines:    20
    Comment lines:  15
    Code lines:     85









































Current Limitations . This is an early version of ForgeAI . The current analyzer:

- Only supports C++ source files
- Uses a basic line-based comment detector
- Does not yet understand C++ syntax
- Does not parse classes or functions
- Does not build a dependency graph
- Does not calculate code complexity
- Does not use a database
- Does not provide a web interface
- Does not use machine learning yet

These limitations are intentional. The project is being developed incrementally, with the goal of building a robust foundation before adding more advanced analysis features.

Roadmap
v1.x — Core Analysis
    Better comment detection
    Source file metadata
    Directory-level statistics
    File ranking
    Improved project reports
v2.x — C++ Code Understanding
    Class detection
    Function detection
    Include/dependency analysis
    Namespace analysis
    Abstract syntax tree integration
v3.x — Code Graph
    Dependency graph
    Call graph
    Include graph
    Graph algorithms
    Codebase relationship analysis
v4.x — Data Platform
    Persistent project storage
    SQL database
    REST API
    Project history
    Analysis comparison

Future — AI Code Intelligence
    AI-assisted code analysis
    Code quality recommendations
    Intelligent project summaries
    Architecture insights
    AI-powered developer assistant
    Tech Stack

Current:
    C++
    C++17
    STL
    std::filesystem
    std::vector
    Git / GitHub

Planned:
    SQL
    REST API
    Web frontend
    Graph algorithms
    Machine Learning / AI

Development Philosoph . ForgeAI is intentionally being developed from the ground up . The project focuses on:
    1. Strong C++ fundamentals
    2. Data structures and algorithms
    3. Clean software architecture
    4. Incremental development
    5. Testable components
    6. Scalable system design
    7. Gradual integration of databases, web technologies and AI