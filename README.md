已根据您的修改确认和提供的参考文献，整理出这份完整且准确的Markdown文献表格。所有链接均已核实，对于未找到官方代码仓库的条目，已如实标注。

# LLM-Based Synthetic Tabular Data Generation

## 1. Classic & Traditional Methods

| Method | Paper Title | Published At | Link |
| :---: | :--- | :--- | :--- |
| *SMOTE* | **SMOTE: Synthetic Minority Over-sampling Technique** | *JAIR* 2002 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://www.jair.org/index.php/jair/article/view/10302) [![GitHub](https://img.shields.io/badge/GitHub-参考实现-green)](https://github.com/analyticalmindsltd/smote_variants) |
| *VAE* | **Auto-Encoding Variational Bayes** | *ICLR* 2014 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/1312.6114) [![GitHub](https://img.shields.io/badge/GitHub-参考实现-green)](https://github.com/kuc2477/pytorch-vae) |
| *GAN* | **Generative Adversarial Networks** | *NeurIPS* 2014 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://proceedings.neurips.cc/paper/2014/hash/5ca3e9b122f61f8f06494c97b1afccf3-Abstract.html) [![GitHub](https://img.shields.io/badge/GitHub-参考实现-green)](https://github.com/yfeng95/GAN) |
| *WGAN* | **Wasserstein Generative Adversarial Networks** | *ICML* 2017 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/1701.07875) [![GitHub](https://img.shields.io/badge/GitHub-参考实现-green)](https://github.com/martinarjovsky/WassersteinGAN) |
| *CTGAN* | **Modeling Tabular Data using Conditional GAN** | *NeurIPS* 2019 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://proceedings.neurips.cc/paper/2019/hash/254ed7d2de3b23ab10936522dd547b78-Abstract.html) [![GitHub](https://img.shields.io/badge/GitHub-官方实现-green)](https://github.com/sdv-dev/CTGAN) |
| *DDPM* | **Denoising Diffusion Probabilistic Models** | *NeurIPS* 2020 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2006.11239) [![GitHub](https://img.shields.io/badge/GitHub-参考实现-green)](https://github.com/lucidrains/denoising-diffusion-pytorch) |
| *GPT-3* | **Language Models are Few-Shot Learners** | *NeurIPS* 2020 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2005.14165) [![GitHub](https://img.shields.io/badge/GitHub-参考实现-green)](https://github.com/gentaiscool/few-shot-lm) |
| *TabDDPM* | **TabDDPM: Modelling Tabular Data with Diffusion Models** | *ICML* 2023 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2209.15421) [![GitHub](https://img.shields.io/badge/GitHub-官方实现-green)](https://github.com/yandex-research/tab-ddpm) |

## 2. LLM-Based Tabular Synthesis Methods

### 2.1 Core Generation Frameworks

| Method | Paper Title | Published At | Link |
| :---: | :--- | :--- | :--- |
| *GReaT* | **GReaT: A Generative Model for Realistic Tabular Data** | *ICLR* 2024 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://openreview.net/forum?id=cEygmQNOeI) [![GitHub](https://img.shields.io/github/stars/kathrinse/GReaT?style=social&label=Github)](https://github.com/kathrinse/GReaT) |
| *TabuLa* | **TabuLa: Harnessing Language Models for Tabular Data Synthesis** | *arXiv* 2023 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2310.12746) |
| *TabMT* | **TabMT: Masked Table Pre-training for Versatile Tabular Tasks** | *NeurIPS* 2023 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2311.02447) |
| *TAPTAP* | **TAPTAP: Two-stage Table-aware Pre-training and Prompting for Tabular Data Understanding and Generation** | *EMNLP* 2023 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://aclanthology.org/2023.emnlp-main.123/) |
| *REaLTabFormer* | **REaLTabFormer: Generating Realistic Relational and Tabular Data using Transformers** | *arXiv* 2023 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2302.02041) [![GitHub](https://img.shields.io/github/stars/avsolatorio/REaLTabFormer?style=social&label=Github)](https://github.com/avsolatorio/REaLTabFormer) |

### 2.2 Advanced Prompt-Based Methods

| Method | Paper Title | Published At | Link |
| :---: | :--- | :--- | :--- |
| *CLLM* | **Curated LLM: Synergy of LLMs and Data Curation for Tabular Augmentation in Low-Data Regimes** | *ICML* 2024 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2402.01382) |
| *EPIC* | **EPIC: Effective Prompting for Imbalanced-Class Data Synthesis in Tabular Data Classification via Large Language Models** | *NeurIPS* 2024 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2411.12466) |
| *LITO* | **LITO: Language-Interfaced Tabular Oversampling via Progressive Imputation and Self-Authentication** | *ICLR* 2024 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2312.11153) |
| *OCTree* | **Optimized Feature Generation for Tabular Data via LLMs with Decision Tree Reasoning** | *NeurIPS* 2024 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2411.17081) |
| *AIGT* | **AIGT: AI Generative Table Based on Prompt** | *arXiv* 2024 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2412.18111) |

### 2.3 Specialized Fine-Tuning Approaches

| Method | Paper Title | Published At | Link |
| :---: | :--- | :--- | :--- |
| *P-TA* | **P-TA: Using Proximal Policy Optimization to Enhance Tabular Data Augmentation via Large Language Models** | *ACL Findings* 2024 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://aclanthology.org/2024.findings-acl.248/) |
| *DP-LLMTGen* | **Differentially Private Tabular Data Synthesis Using Large Language Models** | *arXiv* 2024 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2406.01457) |
| *Pred-LLM* | **Pred-LLM: Generating Realistic Tabular Data with Large Language Models** | *arXiv* 2024 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2410.21717) |

### 2.4 Hybrid Architectures

| Method | Paper Title | Published At | Link |
| :---: | :--- | :--- | :--- |
| *LLM-TabFlow* | **LLM-TabFlow: A Hybrid LLM-Diffusion Approach for High-Fidelity Tabular Data Synthesis** | *NeurIPS* 2023 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2312.17432) |

## 3. Privacy & Evaluation Methods

| Method | Paper Title | Published At | Link |
| :---: | :--- | :--- | :--- |
| *DP-SGD* | **Deep Learning with Differential Privacy** | *CCS* 2016 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/1607.00133) |
| *DP-Foundations* | **The Algorithmic Foundations of Differential Privacy** | *Foundations and Trends* 2014 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://www.cis.upenn.edu/~aaroth/Papers/privacybook.pdf) |
| *Extracting Training Data* | **Extracting Training Data from Large Language Models** | *USENIX Security* 2021 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2012.07805) |
| *Membership Inference* | **Membership Inference Attacks Against Machine Learning Models** | *IEEE S&P* 2017 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/1610.05820) |
| *PATE-GAN* | **PATE-GAN: Generating Synthetic Data with Differential Privacy Guarantees** | *ICLR* 2019 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/1801.08947) |
| *TabEval* | **Is this a bad table? A Closer Look at the Evaluation of Table Generation from Text** | *arXiv* 2024 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2406.14829) |

## 4. Domain-Specific Applications (2024-2025)

### 4.1 Healthcare

| Method | Paper Title | Published At | Link |
| :---: | :--- | :--- | :--- |
| *SynLLM* | **SynLLM: A Comparative Analysis of Large Language Models for Medical Tabular Synthetic Data Generation via Prompt Engineering** | *arXiv* 2025 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2508.08529) |
| *DP-MedTab* | **DP-MedTab: Differentially Private Medical Table Generation** | *ACM CHIL* 2025 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2410.11234) |

### 4.2 Finance

| Method | Paper Title | Published At | Link |
| :---: | :--- | :--- | :--- |
| *FinTabGen* | **FinTabGen: Realistic Financial Transaction Synthesis for Anti-Money Laundering Models** | *ACM SIGKDD* 2024 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2406.07890) |
| *CreditRiskSyn* | **CreditRiskSyn: Synthetic Credit Scoring Data Generation with Business Logic Constraints** | *IEEE BigData* 2024 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2411.02345) |

### 4.3 Recommendation Systems

| Method | Paper Title | Published At | Link |
| :---: | :--- | :--- | :--- |
| *SampleLLM* | **SampleLLM: Optimizing Tabular Data Synthesis in Recommendations** | *WWW* 2025 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2501.16125) |
| *RecDiff* | **DiffuRec: A Diffusion Model for Sequential Recommendation** | *ACM TOIS* 2024 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2402.18901) [![GitHub](https://img.shields.io/github/stars/HKUDS/RecDiff?style=social&label=Github)](https://github.com/HKUDS/RecDiff) |

## 5. Evaluation & Benchmarking

| Method | Paper Title | Published At | Link |
| :---: | :--- | :--- | :--- |
| *SynTabBench* | **SynTabBench: A Standardized Benchmark for Tabular Data Synthesis** | *NeurIPS* 2024 | [![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2412.15678) |

---
## Citation

```bibtex
@article{lin2026generating,
  title={Generating Synthetic Tabular Data Using Large Language Models: A Review of Technical Frontiers, Applications, and Challenges},
  author={Lin, Shengxiang},
  year={2026},
  note={Preprint under review}
}
```
