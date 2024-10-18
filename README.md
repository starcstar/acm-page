# NUAAXCPC Wiki README

[![Deploy VitePress site to Pages](https://github.com/starcstar/acm-page/actions/workflows/deploy.yml/badge.svg?branch=main)](https://github.com/starcstar/acm-page/actions/workflows/deploy.yml)

Website: [https://acm.starcstar.club](https://acm.starcstar.club)

## Generate Slides

```bash
python3 scripts/build-marp.py
```

## Build

```bash
yarn install
yarn run docs:build
```

## Development

```bash
yarn run docs:dev
```

Any files named `slide.md` in the `docs` directory will be automatically rendered as marp slides.

Any changes to the `main` branch will be automatically deployed to the website.