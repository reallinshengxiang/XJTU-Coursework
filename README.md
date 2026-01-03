# LLM-Based Synthetic Tabular Data Generation

## 1. Survey & Classic Methods

### 1.1 Tabular Data Learning Survey

|Method/Type|Paper Title|Published At|Link|
|---|---|---|---|
|*DNN-Tabular Survey*|**Deep Neural Networks and Tabular Data: A Survey**|IEEE TNNLS 2022|[![Paper](https://img.shields.io/badge/Paper-blue)](https://ieeexplore.ieee.org/document/9437761) [![Github](https://img.shields.io/github/stars/kathrinse/TabSurvey?style=social&label=Github)](https://github.com/kathrinse/TabSurvey)|
|*LLM-Tabular Survey*|**Large Language Models (LLMs) on Tabular Data: Prediction, Generation, and Understanding—A Survey**|arXiv 2024|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2402.17944) [![Github](https://img.shields.io/github/stars/tanfiona/LLM-on-Tabular-Data-Prediction-Table-Understanding-Data-Generation?style=social&label=Github)](https://github.com/tanfiona/LLM-on-Tabular-Data-Prediction-Table-Understanding-Data-Generation)|
### 1.2 Traditional Synthetic Data Methods

|Method|Paper Title|Published At|Link|
|---|---|---|---|
|*SMOTE*|**SMOTE: Synthetic Minority Over-sampling Technique**|JAIR 2002|[![Paper](https://img.shields.io/badge/Paper-blue)](https://www.jair.org/index.php/jair/article/view/10302) [![Github](https://img.shields.io/github/stars/analyticalmindsltd/smote_variants?style=social&label=Github)](https://github.com/analyticalmindsltd/smote_variants)|
|*VAE*|**Auto-Encoding Variational Bayes**|arXiv 2013|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/1312.6114) [![Github](https://img.shields.io/github/stars/kuc2477/pytorch-vae?style=social&label=Github)](https://github.com/kuc2477/pytorch-vae)|
|*GAN*|**Generative Adversarial Nets**|NeurIPS 2014|[![Paper](https://img.shields.io/badge/Paper-blue)](https://proceedings.neurips.cc/paper/2014/hash/5ca3e9b122f61f8f06494c97b1afccf3-Abstract.html) [![Github](https://img.shields.io/github/stars/goodfeli/adversarial?style=social&label=Github)](https://github.com/goodfeli/adversarial)|
|*WGAN*|**Wasserstein Generative Adversarial Networks**|ICML 2017|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/1701.07875) [![Github](https://img.shields.io/github/stars/martinarjovsky/WassersteinGAN?style=social&label=Github)](https://github.com/martinarjovsky/WassersteinGAN)|
|*CTGAN*|**Modeling Tabular Data using Conditional GAN**|NeurIPS 2019|[![Paper](https://img.shields.io/badge/Paper-blue)](https://proceedings.neurips.cc/paper/2019/hash/254ed7d2de3b23ab10936522dd547b78-Abstract.html) [![Github](https://img.shields.io/github/stars/sdv-dev/CTGAN?style=social&label=Github)](https://github.com/sdv-dev/CTGAN)|
|*DDPM*|**Denoising Diffusion Probabilistic Models**|NeurIPS 2020|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2006.11239) [![Github](https://img.shields.io/github/stars/hojonathanho/diffusion?style=social&label=Github)](https://github.com/hojonathanho/diffusion)|
|*GPT-3*|**Language Models are Few-Shot Learners**|NeurIPS 2020|[![Paper](https://img.shields.io/badge/Paper-blue)](https://proceedings.neurips.cc/paper/2020/hash/1457c0d6bfcb4967418bfb8ac142f64a-Abstract.html)|
|*TabDDPM*|**TabDDPM: Modelling Tabular Data with Diffusion Models**|ICML 2023|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2209.15421) [![Github](https://img.shields.io/github/stars/yandex-research/tab-ddpm?style=social&label=Github)](https://github.com/yandex-research/tab-ddpm)|
## 2. LLM-Based Tabular Synthesis Methods

### 2.1 Core Generation Frameworks

|Method|Paper Title|Published At|Link|
|---|---|---|---|
|*GReaT*|**GReaT: A generative model for realistic tabular data**|arXiv 2023|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2308.01785) [![Github](https://img.shields.io/github/stars/tabularis-ai/be_great?style=social&label=Github)](https://github.com/tabularis-ai/be_great)|
|*TabuLa*|**TabuLa: Harnessing Language Models for Tabular Data Synthesis**|arXiv 2023|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2310.12746) [![Github](https://img.shields.io/github/stars/zhao-zilong/Tabula?style=social&label=Github)](https://github.com/zhao-zilong/Tabula)|
|*TabMT*|**TabMT: Masked Table Pre-training for Versatile Tabular Tasks**|NeurIPS 2023|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2311.02447)|
|*TAPTAP*|**Generative Table Pre-training Empowers Models for Tabular Prediction**|EMNLP 2023|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2305.09696) [![Github](https://img.shields.io/github/stars/ZhangTP1996/TapTap?style=social&label=Github)](https://github.com/ZhangTP1996/TapTap)|
|*REaLTabFormer*|**REaLTabFormer: Generating Realistic Relational and Tabular Data using Transformers**|arXiv 2023|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2302.02041) [![Github](https://img.shields.io/github/stars/worldbank/REaLTabFormer?style=social&label=Github)](https://github.com/worldbank/REaLTabFormer)|
### 2.2 Advanced Prompt-Based Methods

|Method|Paper Title|Published At|Link|
|---|---|---|---|
|*CLLM*|**Curated LLM: Synergy of LLMs and Data Curation for Tabular Augmentation in Low-Data Regimes**|ICML 2024|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2312.12112) [![Github](https://img.shields.io/github/stars/seedatnabeel/CLLM?style=social&label=Github)](https://github.com/seedatnabeel/CLLM)|
|*EPIC*|**EPIC: Effective Prompting for Imbalanced-Class Data Synthesis in Tabular Data Classification via Large Language Models**|NeurIPS 2024|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2404.12404) [![Github](https://img.shields.io/github/stars/seharanul17/synthetic-tabular-LLM?style=social&label=Github)](https://github.com/seharanul17/synthetic-tabular-LLM)|
|*LITO*|**Language-Interfaced Tabular Oversampling via Progressive Imputation and Self-Authentication**|ICLR 2024|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2312.11153)|
|*OCTree*|**Optimized Feature Generation for Tabular Data via LLMs with Decision Tree Reasoning**|NeurIPS 2024|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2406.08527) [![Github](https://img.shields.io/github/stars/jaehyun513/OCTree?style=social&label=Github)](https://github.com/jaehyun513/OCTree)|
|*AIGT*|**AIGT: AI Generative Table Based on Prompt**|arXiv 2024|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2412.18111)|
### 2.3 Specialized Fine-Tuning Approaches

|Method|Paper Title|Published At|Link|
|---|---|---|---|
|*P-TA*|**P-TA: Using Proximal Policy Optimization to Enhance Tabular Data Augmentation via Large Language Models**|ACL Findings 2024|[![Paper](https://img.shields.io/badge/Paper-blue)](https://aclanthology.org/2024.findings-acl.248/)|
|*DP-LLMTGen*|**Differentially Private Tabular Data Synthesis using Large Language Models**|arXiv 2024|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2406.01457)|
|*Pred-LLM*|**Generating Realistic Tabular Data with Large Language Models**|arXiv 2024|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2410.21717) [![Github](https://img.shields.io/github/stars/nphdang/Pred-LLM?style=social&label=Github)](https://github.com/nphdang/Pred-LLM)|
### 2.4 Hybrid Architectures

|Method|Paper Title|Published At|Link|
|---|---|---|---|
|*LLM-TabFlow*|**LLM-TabFlow: A Hybrid LLM-Diffusion Approach for High-Fidelity Tabular Data Synthesis**|NeurIPS 2023|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2503.02161)|
## 3. Privacy & Security Methods

|Method/Topic|Paper Title|Published At|Link|
|---|---|---|---|
|*DP-SGD*|**Deep Learning with Differential Privacy**|CCS 2016|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/1607.00133)|
|*DP-Foundations*|**The Algorithmic Foundations of Differential Privacy**|Foundations and Trends 2014|[![Paper](https://img.shields.io/badge/Paper-blue)](https://www.cis.upenn.edu/~aaroth/Papers/privacybook.pdf)|
|*Training Data Extraction*|**Extracting Training Data from Large Language Models**|USENIX Security 2021|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2012.07805) [![Github](https://img.shields.io/github/stars/ftramer/LM_Memorization?style=social&label=Github)](https://github.com/ftramer/LM_Memorization)|
|*Membership Inference*|**Membership Inference Attacks Against Machine Learning Models**|IEEE S&P 2017|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/1610.05820)|
|*PATE-GAN*|**PATE-GAN: Generating Synthetic Data with Differential Privacy Guarantees**|ICLR 2018|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/1801.08947) [![Github](https://img.shields.io/github/stars/BorealisAI/private-data-generation?style=social&label=Github)](https://github.com/BorealisAI/private-data-generation)|
|*Memorization Analysis*|**An Empirical Analysis of Memorization in Fine-tuned Autoregressive Language Models**|EMNLP 2022|[![Paper](https://img.shields.io/badge/Paper-blue)](https://aclanthology.org/2022.emnlp-main.607/)|
|*Privacy-Risk & Overfitting*|**Privacy Risk in Machine Learning: Analyzing the Connection to Overfitting**|IEEE CSF 2018|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/1709.01604) [![Github](https://img.shields.io/github/stars/sam-yeom/ml-privacy-csf18?style=social&label=Github)](https://github.com/sam-yeom/ml-privacy-csf18)|
## 4. Domain-Specific Applications (2023-2025)

### 4.1 Healthcare

|Method|Paper Title|Published At|Link|
|---|---|---|---|
|*SynLLM*|**SynLLM: A Comparative Analysis of Large Language Models for Medical Tabular Synthetic Data Generation via Prompt Engineering**|arXiv 2025|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2508.08529)|
### 4.2 Finance

|Method|Paper Title|Published At|Link|
|---|---|---|---|
|*FinSyn*|**Realistic Synthetic Financial Transactions for Anti-Money Laundering Models**|Workshop on Data Science for Macro-Modeling 2023|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2306.09739) [![Github](https://img.shields.io/github/stars/IBM/Multi-GNN?style=social&label=Github)](https://github.com/IBM/Multi-GNN)|
### 4.3 Recommendation Systems

|Method|Paper Title|Published At|Link|
|---|---|---|---|
|*SampleLLM*|**SampleLLM: Optimizing Tabular Data Synthesis in Recommendations**|WWW 2025|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2501.16125)|
|*DiffuRec*|**DiffuRec: A Diffusion Model for Sequential Recommendation**|ACM TOIS 2024|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2304.00686) [![Github](https://img.shields.io/github/stars/WHUIR/DiffuRec?style=social&label=Github)](https://github.com/WHUIR/DiffuRec)|
|*PrivRec*|**Privacy-Preserving Sequential Recommendation with Collaborative Confusion**|ACM TOIS 2025|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2401.04423) [![Github](https://img.shields.io/github/stars/weiwang0927/CLOUD?style=social&label=Github)](https://github.com/weiwang0927/CLOUD)|
## 5. Evaluation & Benchmarking

|Method/Benchmark|Paper Title|Published At|Link|
|---|---|---|---|
|*TabSynthEval*|**Towards Standardized Evaluation of Synthetic Tabular Data: Metrics, Benchmarks, and Best Practices**|ICDM 2024|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2405.11117) [![Github](https://img.shields.io/github/stars/Vicomtech/STDG-evaluation-metrics?style=social&label=Github)](https://github.com/Vicomtech/STDG-evaluation-metrics)|
## 6. Supplementary Topics

### 6.1 Imbalanced Data Learning

|Method/Topic|Paper Title|Published At|Link|
|---|---|---|---|
|*Imbalanced Learning Survey*|**Learning from Imbalanced Data**|IEEE TKDE 2009|[![Paper](https://img.shields.io/badge/Paper-blue)](https://ieeexplore.ieee.org/document/4685528)|
|*Data Augmentation Survey*|**A Survey on Image Data Augmentation for Deep Learning**|Journal of Big Data 2019|[![Paper](https://img.shields.io/badge/Paper-blue)](https://journalofbigdata.springeropen.com/articles/10.1186/s40537-019-0197-0)|
### 6.2 Missing Data Analysis

|Topic|Book/Paper Title|Published At|Link|
|---|---|---|---|
|*Missing Data Analysis*|**Statistical Analysis with Missing Data** (Vol. 793)|John Wiley & Sons 2019|[![Book](https://img.shields.io/badge/Book-orange)](https://onlinelibrary.wiley.com/book/10.1002/9781119482260)|
### 6.3 LLM Optimization

|Method|Paper Title|Published At|Link|
|---|---|---|---|
|*LoRA*|**LoRA: Low-Rank Adaptation of Large Language Models**|arXiv 2021|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2106.09685) [![Github](https://img.shields.io/github/stars/microsoft/LoRA?style=social&label=Github)](https://github.com/microsoft/LoRA)|
|*DistilBERT*|**DistilBERT, a Distilled Version of BERT: Smaller, Faster, Cheaper and Lighter**|arXiv 2019|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/1910.01108) [![Github](https://img.shields.io/github/stars/huggingface/transformers?style=social&label=Github)](https://github.com/huggingface/transformers)|
|*LLaMA*|**LLaMA: Open and Efficient Foundation Language Models**|arXiv 2023|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2302.13971) [![Github](https://img.shields.io/github/stars/meta-llama/llama?style=social&label=Github)](https://github.com/meta-llama/llama)|

## Citation

```bibtex
@article{lin2025generating,
  title={Generating Synthetic Tabular Data Using Large Language Models: A Review of Technical Frontiers, Applications, and Challenges},
  author={Lin, Shengxiang},
  year={2026}
}
```
