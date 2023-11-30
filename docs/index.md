# Welcome to MkDocs

For full documentation visit [mkdocs.org](https://www.mkdocs.org).

## Commands

* `mkdocs new [dir-name]` - Create a new project.
* `mkdocs serve` - Start the live-reloading docs server.
* `mkdocs build` - Build the documentation site.
* `mkdocs -h` - Print help message and exit.

## Project layout

    mkdocs.yml    # The configuration file.
    docs/
        index.md  # The documentation homepage.
        ...       # Other markdown pages, images and other files.

## Notes

### zsh中运行mkdocs报错`command not found`

#### 设置alias运行

- ubuntu输入`bash`
    - ![](image.png)
- 输入`chsh -s /bin/bash`
  - 按照要求输入密码：********
- 打开一个新的ubuntu窗口，输入`whereis mkdocs`
  - ![Alt text](image-1.png)
  - 复制路径
- 回到最初的窗口（zsh）中输入
  - ![Alt text](image-2.png) ##在zsh中添加路径设置别名
- 返回到zsh的bash里面：`chsh -s /bin/zsh`
- 注意这是单次终端，这意味着每次打开ubuntu运行mkdocs的时候都需要重新一次设置别名。

