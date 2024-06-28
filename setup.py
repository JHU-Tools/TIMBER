import setuptools, sys

with open("README.md", "r") as fh:
    long_description = fh.read()

setuptools.setup(
    name="TIMBER",
    version="1.0.0",
    author="mrogulji",
    author_email="matej.roguljic@gmail.com",
    description="Tree Interface for Making Binned Events with RDataFrame",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://github.com/JHU-Tools/TIMBER/tree/master",
    packages=setuptools.find_packages(),
    include_package_data=True,
    # cmdclass={'install': AddToPath},
    install_requires = [
        "decorator>=4.4.2",
        "pyparsing>=2.4.7",
        #"graphviz==0.14.2",
        "pydot>=1.4.1",
        "networkx>=2.2",
        "clang>=6.0.0.2",
        "numpy>=1.16.6",
        "pandas>=0.24.2,<2.0" #dataframe.append is removed in v2.0 so TIMBER code will have to be adapted to that
    ]
)

