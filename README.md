# LLM-Based Synthetic Tabular Data Generation

## 1. Survey & Classic Methods

### 1.1 Tabular Data Learning Survey

|Method/Type|Paper Title|Published At|Link|
|---|---|---|---|
|*DNN-Tabular Survey*|**Deep Neural Networks and Tabular Data: A Survey**|IEEE TNNLS 2022|[![Paper](https://img.shields.io/badge/Paper-blue)](https://ieeexplore.ieee.org/document/9437761) [![Github](https://img.shields.io/github/stars/search?query=Deep+Neural+Networks+and+Tabular+Data+Survey&style=social&label=Github)](https://github.com/search?q=Deep+Neural+Networks+and+Tabular+Data+Survey)|
|*LLM-Tabular Survey*|**Large Language Models (LLMs) on Tabular Data: Prediction, Generation, and Understanding—A Survey**|arXiv 2024|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2402.17944) [![Github](https://img.shields.io/github/stars/search?query=LLMs+on+Tabular+Data+Survey&style=social&label=Github)](https://github.com/search?q=LLMs+on+Tabular+Data+Survey)|
### 1.2 Traditional Synthetic Data Methods

|Method|Paper Title|Published At|Link|
|---|---|---|---|
|*SMOTE*|**SMOTE: Synthetic Minority Over-sampling Technique**|JAIR 2002|[![Paper](https://img.shields.io/badge/Paper-blue)](https://www.jair.org/index.php/jair/article/view/10302) [![Github](https://img.shields.io/github/stars/analyticalmindsltd/smote_variants?style=social&label=Github)](https://github.com/analyticalmindsltd/smote_variants)|
|*VAE*|**Auto-encoding Variational Bayes**|ICLR 2014|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/1312.6114) [![Github](https://img.shields.io/github/stars/kuc2477/pytorch-vae?style=social&label=Github)](https://github.com/kuc2477/pytorch-vae)|
|*GAN*|**Generative Adversarial Nets**|NeurIPS 2014|[![Paper](https://img.shields.io/badge/Paper-blue)](https://proceedings.neurips.cc/paper/2014/hash/5ca3e9b122f61f8f06494c97b1afccf3-Abstract.html) [![Github](https://img.shields.io/github/stars/yfeng95/GAN?style=social&label=Github)](https://github.com/yfeng95/GAN)|
|*WGAN*|**Wasserstein Generative Adversarial Networks**|ICML 2017|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/1701.07875) [![Github](https://img.shields.io/github/stars/martinarjovsky/WassersteinGAN?style=social&label=Github)](https://github.com/martinarjovsky/WassersteinGAN)|
|*CTGAN*|**Modeling Tabular Data using Conditional GAN**|NeurIPS 2019|[![Paper](https://img.shields.io/badge/Paper-blue)](https://proceedings.neurips.cc/paper/2019/hash/254ed7d2de3b23ab10936522dd547b78-Abstract.html) [![Github](https://img.shields.io/github/stars/qusaii21/Synthetic-Data-Generation-for-Enhanced-Model-Efficiency-A-GAN-Based-Approach-to-Tabular-Data?style=social&label=Github)](https://github.com/qusaii21/Synthetic-Data-Generation-for-Enhanced-Model-Efficiency-A-GAN-Based-Approach-to-Tabular-Data)|
|*DDPM*|**Denoising Diffusion Probabilistic Models**|NeurIPS 2020|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2006.11239) [![Github](https://img.shields.io/github/stars/lucidrains/denoising-diffusion-pytorch?style=social&label=Github)](https://github.com/lucidrains/denoising-diffusion-pytorch)|
|*GPT-3*|**Language Models are Few-Shot Learners**|NeurIPS 2020|[![Paper](https://img.shields.io/badge/Paper-blue)](https://proceedings.neurips.cc/paper/2020/hash/1457c0d6bfcb4967418bfb8ac142f64a-Abstract.html) [![Github](https://img.shields.io/github/stars/gentaiscool/few-shot-lm?style=social&label=Github)](https://github.com/gentaiscool/few-shot-lm)|
|*TabDDPM*|**TabDDPM: Modelling Tabular Data with Diffusion Models**|ICML 2023|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2209.15421) [![Github](https://img.shields.io/github/stars/yandex-research/tab-ddpm?style=social&label=Github)](https://github.com/yandex-research/tab-ddpm)|
## 2. LLM-Based Tabular Synthesis Methods

### 2.1 Core Generation Frameworks

|Method|Paper Title|Published At|Link|
|---|---|---|---|
|*GReaT*|**GReaT: A generative model for realistic tabular data**|arXiv 2023|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2308.01785) [![Github](https://img.shields.io/github/stars/kathrinse/GReaT?style=social&label=Github)](https://github.com/kathrinse/GReaT)|
|*TabuLa*|**TabuLa: Harnessing language models for tabular data synthesis**|arXiv 2023|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2310.12746) [![Github](https://img.shields.io/github/stars/search?query=TabuLa+tabular+data+synthesis&style=social&label=Github)](https://github.com/search?q=TabuLa+tabular+data+synthesis)|
|*TabMT*|**TabMT: Masked table pre-training for versatile tabular tasks**|NeurIPS 2023|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2311.02447) [![Github](https://img.shields.io/github/stars/search?query=TabMT+masked+table+pre-training&style=social&label=Github)](https://github.com/search?q=TabMT+masked+table+pre-training)|
|*TAPTAP*|**TAPTAP: Two-stage table-aware pre-training and prompting for tabular data understanding and generation**|EMNLP 2023|[![Paper](https://img.shields.io/badge/Paper-blue)](https://aclanthology.org/2023.emnlp-main.123/) [![Github](https://img.shields.io/github/stars/search?query=TAPTAP+table-aware+pre-training&style=social&label=Github)](https://github.com/search?q=TAPTAP+table-aware+pre-training)|
|*REaLTabFormer*|**REaLTabFormer: Generating realistic relational and tabular data using transformers**|arXiv 2023|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2302.02041) [![Github](https://img.shields.io/github/stars/avsolatorio/REaLTabFormer?style=social&label=Github)](https://github.com/avsolatorio/REaLTabFormer)|
### 2.2 Advanced Prompt-Based Methods

|Method|Paper Title|Published At|Link|
|---|---|---|---|
|*CLLM*|**Curated LLM: Synergy of LLMs and data curation for tabular augmentation in low-data regimes**|ICML 2024|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2402.01382) [![Github](https://img.shields.io/github/stars/search?query=CLLM+tabular+augmentation&style=social&label=Github)](https://github.com/search?q=CLLM+tabular+augmentation)|
|*EPIC*|**EPIC: Effective prompting for imbalanced-class data synthesis in tabular data classification via large language models**|NeurIPS 2024|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2411.12466) [![Github](https://img.shields.io/github/stars/search?query=EPIC+imbalanced-class+tabular+synthesis&style=social&label=Github)](https://github.com/search?q=EPIC+imbalanced-class+tabular+synthesis)|
|*LITO*|**Language-interfaced tabular oversampling via progressive imputation and self-authentication**|ICLR 2024|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2312.11153) [![Github](https://img.shields.io/github/stars/search?query=LITO+tabular+oversampling&style=social&label=Github)](https://github.com/search?q=LITO+tabular+oversampling)|
|*OCTree*|**Optimized feature generation for tabular data via LLMs with decision tree reasoning**|NeurIPS 2024|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2411.17081) [![Github](https://img.shields.io/github/stars/search?query=OCTree+LLM+tabular+feature+generation&style=social&label=Github)](https://github.com/search?q=OCTree+LLM+tabular+feature+generation)|
|*AIGT*|**AIGT: AI generative table based on prompt**|arXiv 2024|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2412.18111) [![Github](https://img.shields.io/github/stars/search?query=AIGT+AI+generative+table&style=social&label=Github)](https://github.com/search?q=AIGT+AI+generative+table)|
### 2.3 Specialized Fine-Tuning Approaches

|Method|Paper Title|Published At|Link|
|---|---|---|---|
|*P-TA*|**P-TA: Using proximal policy optimization to enhance tabular data augmentation via large language models**|ACL Findings 2024|[![Paper](https://img.shields.io/badge/Paper-blue)](https://aclanthology.org/2024.findings-acl.248/) [![Github](https://img.shields.io/github/stars/search?query=P-TA+tabular+data+augmentation+PPO&style=social&label=Github)](https://github.com/search?q=P-TA+tabular+data+augmentation+PPO)|
|*DP-LLMTGen*|**Differentially private tabular data synthesis using large language models**|arXiv 2024|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2406.01457) [![Github](https://img.shields.io/github/stars/search?query=DP-LLMTGen+differentially+private+tabular+synthesis&style=social&label=Github)](https://github.com/search?q=DP-LLMTGen+differentially+private+tabular+synthesis)|
|*Pred-LLM*|**Generating realistic tabular data with large language models**|arXiv 2024|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2410.21717) [![Github](https://img.shields.io/github/stars/search?query=Pred-LLM+tabular+data+generation&style=social&label=Github)](https://github.com/search?q=Pred-LLM+tabular+data+generation)|
### 2.4 Hybrid Architectures

|Method|Paper Title|Published At|Link|
|---|---|---|---|
|*LLM-TabFlow*|**LLM-TabFlow: A hybrid LLM-diffusion approach for high-fidelity tabular data synthesis**|NeurIPS 2023|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2312.17432) [![Github](https://img.shields.io/github/stars/search?query=LLM-TabFlow+LLM-diffusion+tabular+synthesis&style=social&label=Github)](https://github.com/search?q=LLM-TabFlow+LLM-diffusion+tabular+synthesis)|
## 3. Privacy & Security Methods

|Method/Topic|Paper Title|Published At|Link|
|---|---|---|---|
|*DP-SGD*|**Deep learning with differential privacy**|CCS 2016|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/1607.00133) [![Github](https://img.shields.io/github/stars/search?query=DP-SGD+differential+privacy+deep+learning&style=social&label=Github)](https://github.com/search?q=DP-SGD+differential+privacy+deep+learning)|
|*DP-Foundations*|**The algorithmic foundations of differential privacy**|Foundations and Trends 2014|[![Paper](https://img.shields.io/badge/Paper-blue)](https://www.cis.upenn.edu/~aaroth/Papers/privacybook.pdf) [![Github](https://img.shields.io/github/stars/search?query=algorithmic+foundations+of+differential+privacy&style=social&label=Github)](https://github.com/search?q=algorithmic+foundations+of+differential+privacy)|
|*Training Data Extraction*|**Extracting training data from large language models**|USENIX Security 2021|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2012.07805) [![Github](https://img.shields.io/github/stars/search?query=training+data+extraction+LLM&style=social&label=Github)](https://github.com/search?q=training+data+extraction+LLM)|
|*Membership Inference*|**Membership inference attacks against machine learning models**|IEEE S&P 2017|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/1610.05820) [![Github](https://img.shields.io/github/stars/search?query=membership+inference+attacks+machine+learning&style=social&label=Github)](https://github.com/search?q=membership+inference+attacks+machine+learning)|
|*PATE-GAN*|**PATE-GAN: Generating synthetic data with differential privacy guarantees**|ICLR 2018|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/1801.08947) [![Github](https://img.shields.io/github/stars/search?query=PATE-GAN+differential+privacy+synthetic+data&style=social&label=Github)](https://github.com/search?q=PATE-GAN+differential+privacy+synthetic+data)|
|*Memorization Analysis*|**An empirical analysis of memorization in fine-tuned autoregressive language models**|EMNLP 2022|[![Paper](https://img.shields.io/badge/Paper-blue)](https://aclanthology.org/2022.emnlp-main.607/) [![Github](https://img.shields.io/github/stars/search?query=memorization+analysis+fine-tuned+LLM&style=social&label=Github)](https://github.com/search?q=memorization+analysis+fine-tuned+LLM)|
|*Privacy-Risk & Overfitting*|**Privacy risk in machine learning: Analyzing the connection to overfitting**|IEEE CSF 2018|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/1709.01604) [![Github](https://img.shields.io/github/stars/search?query=privacy+risk+machine+learning+overfitting&style=social&label=Github)](https://github.com/search?q=privacy+risk+machine+learning+overfitting)|
## 4. Domain-Specific Applications (2023-2025)

### 4.1 Healthcare

|Method|Paper Title|Published At|Link|
|---|---|---|---|
|*SynLLM*|**SynLLM: A Comparative Analysis of Large Language Models for Medical Tabular Synthetic Data Generation via Prompt Engineering**|arXiv 2025|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2508.08529) [![Github](https://img.shields.io/github/stars/search?query=SynLLM+medical+tabular+synthesis&style=social&label=Github)](https://github.com/search?q=SynLLM+medical+tabular+synthesis)|
### 4.2 Finance

|Method|Paper Title|Published At|Link|
|---|---|---|---|
|*FinSyn*|**Realistic Synthetic Financial Transactions for Anti-Money Laundering Models**|Workshop on Data Science for Macro-Modeling 2023|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2306.09739) [![Github](https://img.shields.io/github/stars/search?query=FinSyn+financial+transaction+synthetic+data&style=social&label=Github)](https://github.com/search?q=FinSyn+financial+transaction+synthetic+data)|
### 4.3 Recommendation Systems

|Method|Paper Title|Published At|Link|
|---|---|---|---|
|*SampleLLM*|**SampleLLM: Optimizing Tabular Data Synthesis in Recommendations**|WWW 2025|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2501.16125) [![Github](https://img.shields.io/github/stars/search?query=SampleLLM+tabular+synthesis+recommendation&style=social&label=Github)](https://github.com/search?q=SampleLLM+tabular+synthesis+recommendation)|
|*DiffuRec*|**DiffuRec: A Diffusion Model for Sequential Recommendation**|ACM TOIS 2024|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2402.18901) [![Github](https://img.shields.io/github/stars/search?query=DiffuRec+diffusion+sequential+recommendation&style=social&label=Github)](https://github.com/search?q=DiffuRec+diffusion+sequential+recommendation)|
|*PrivRec*|**Privacy-Preserving Sequential Recommendation with Collaborative Confusion**|ACM TOIS 2025|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2408.08321) [![Github](https://img.shields.io/github/stars/search?query=PrivRec+privacy-preserving+sequential+recommendation&style=social&label=Github)](https://github.com/search?q=PrivRec+privacy-preserving+sequential+recommendation)|
## 5. Evaluation & Benchmarking

|Method/Benchmark|Paper Title|Published At|Link|
|---|---|---|---|
|*TabSynthEval*|**Towards standardized evaluation of synthetic tabular data: Metrics, benchmarks, and best practices**|ICDM 2024|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2405.11117) [![Github](https://img.shields.io/github/stars/search?query=TabSynthEval+synthetic+tabular+evaluation&style=social&label=Github)](https://github.com/search?q=TabSynthEval+synthetic+tabular+evaluation)|
## 6. Supplementary Topics

### 6.1 Imbalanced Data Learning

|Method/Topic|Paper Title|Published At|Link|
|---|---|---|---|
|*Imbalanced Learning Survey*|**Learning from imbalanced data**|IEEE TKDE 2009|[![Paper](https://img.shields.io/badge/Paper-blue)](https://ieeexplore.ieee.org/document/4685528) [![Github](https://img.shields.io/github/stars/search?query=learning+from+imbalanced+data+survey&style=social&label=Github)](https://github.com/search?q=learning+from+imbalanced+data+survey)|
|*Data Augmentation Survey*|**A survey on image data augmentation for deep learning**|Journal of Big Data 2019|[![Paper](https://img.shields.io/badge/Paper-blue)](https://journalofbigdata.springeropen.com/articles/10.1186/s40537-019-0197-0) [![Github](https://img.shields.io/github/stars/search?query=image+data+augmentation+survey+deep+learning&style=social&label=Github)](https://github.com/search?q=image+data+augmentation+survey+deep+learning)|
### 6.2 Missing Data Analysis

|Topic|Book/Paper Title|Published At|Link|
|---|---|---|---|
|*Missing Data Analysis*|**Statistical Analysis with Missing Data** (Vol. 793)|John Wiley & Sons 2019|[![Book](https://img.shields.io/badge/Book-orange)](https://onlinelibrary.wiley.com/book/10.1002/9781119482260) [![Github](https://img.shields.io/github/stars/search?query=statistical+analysis+with+missing+data&style=social&label=Github)](https://github.com/search?q=statistical+analysis+with+missing+data)|
### 6.3 LLM Optimization

|Method|Paper Title|Published At|Link|
|---|---|---|---|
|*LoRA*|**LoRA: Low-rank adaptation of large language models**|arXiv 2021|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2106.09685) [![Github](https://img.shields.io/github/stars/microsoft/LoRA?style=social&label=Github)](https://github.com/microsoft/LoRA)|
|*DistilBERT*|**DistilBERT, a distilled version of BERT: smaller, faster, cheaper and lighter**|arXiv 2019|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/1910.01108) [![Github](https://img.shields.io/github/stars/huggingface/transformers?style=social&label=Github)](https://github.com/huggingface/transformers)|
|*LLaMA*|**Llama: Open and efficient foundation language models**|arXiv 2023|[![Paper](https://img.shields.io/badge/Paper-blue)](https://arxiv.org/abs/2302.13971) [![Github](https://img.shields.io/github/stars/facebookresearch/llama?style=social&label=Github)](https://github.com/facebookresearch/ll|

## Citation

```bibtex

@article{lin2025generating,
  title={Generating Synthetic Tabular Data Using Large Language Models: A Review of Technical Frontiers, Applications, and Challenges},
  author={Lin, Shengxiang},
  year={2026},
  note={Preprint under review}
}
```
