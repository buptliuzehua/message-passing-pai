# PERCOLATE

[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger)

Dillinger is a cloud-enabled, mobile-ready, offline-storage, AngularJS powered HTML5 Markdown editor.

  * [Table of Contents](##table-of-contents)

# Table of Contents

  * [Background](#background)
  * [Environment](#environment)
  * [Structure](#structure)
  * [Install](#install)
  * [Usage](#usage)
  * [Additional Infromation](#additional-infromation)


## Background
<br />
#### What does the program do
The program creates a grid. Each square is randomly assigned to be empty 1 or filled 0 according to the designed density distribution of filled squares. Each empty square is then assigned a unique number. The program iteratively updates the grid, updating each square is updated with the maximum of its neighbours. When an iteration results in no squares being updated, the iteration exits. The program then checks whether there is a cluster on the top row of the grid that has the same number as one on the bottom row i.e. it checks whether percolation has occurred.

#### Output of the program
The program writes out two files. The first is a data file which contains the values of each empty square when each square can be no longer updated i.e. the final state of the grid.The second file is a type of image file, a Portable Grey Map (PGM) file. The largest cluster will be coloured black. Other clusters will be shades of grey, the smaller the cluster the lighter the shade. The filled squares will be coloured white.

#### My work
Though the program works, and has no bugs that the authors are aware of, it is poorly commented, badly laid out, has cryptic variable names and is not modular. It need to be refactored in following goals:
- Clean up and refactor the source code to make it more readable, better commented, and more modular.
- Extend the program to allow the user to specify the values for the grid size, data file name, PGM file name, rho, seed and maximum number of clusters in the PGM file via the command-line as commandline arguments or parameters.
- Write a build script which allows a user to:
&nbsp;&nbsp;&nbsp;&nbsp;Compile and link the source code into an executable.
&nbsp;&nbsp;&nbsp;&nbsp;Remove any auto-generated files created during compilation, linking or when running the program.
&nbsp;&nbsp;&nbsp;&nbsp;Show the help document of how to use it.
- Write documentation, in a plain-text file, on how a user can build and run the program and provide any other information you think a user would find useful.

# Environment
 - GNU Compiler
 - Linux Operation System

# Structure

.  
├── Makefile  
├── README.md
├── config.mk
├── src
│   ├── arralloc.c
│   ├── arralloc.h
│   ├── getColourInfo.h
│   ├── gridInitialise.h
│   ├── gridResult.h
│   ├── gridUpdate.h
│   ├── initAll.h
│   ├── percolate.c
│   ├── structlib.h
│   ├── uni.c
│   ├── uni.h
│   ├── writeDataFile.h
│   └── writePgmFile.h
└── tree.txt

- The src folder contains the source code
- Make is the script to compile and link the source code
- The config.mk contains the environment variables used in Makefile
- tree.txt contains the structure of the whole project


### Installation

Dillinger requires [Node.js](https://nodejs.org/) v4+ to run.

Install the dependencies and devDependencies and start the server.

```sh
$ cd dillinger
$ npm install -d
$ node app
```

For production environments...

```sh
$ npm install --production
$ NODE_ENV=production node app
```

### Plugins

Dillinger is currently extended with the following plugins. Instructions on how to use them in your own application are linked below.

| Plugin | README |
| ------ | ------ |
| Dropbox | [plugins/dropbox/README.md][PlDb] |
| GitHub | [plugins/github/README.md][PlGh] |
| Google Drive | [plugins/googledrive/README.md][PlGd] |
| OneDrive | [plugins/onedrive/README.md][PlOd] |
| Medium | [plugins/medium/README.md][PlMe] |
| Google Analytics | [plugins/googleanalytics/README.md][PlGa] |


### Development

Want to contribute? Great!

Dillinger uses Gulp + Webpack for fast developing.
Make a change in your file and instantanously see your updates!

Open your favorite Terminal and run these commands.

First Tab:
```sh
$ node app
```

Second Tab:
```sh
$ gulp watch
```

(optional) Third:
```sh
$ karma test
```
#### Building for source
For production release:
```sh
$ gulp build --prod
```
Generating pre-built zip archives for distribution:
```sh
$ gulp build dist --prod
```
### Docker
Dillinger is very easy to install and deploy in a Docker container.

By default, the Docker will expose port 8080, so change this within the Dockerfile if necessary. When ready, simply use the Dockerfile to build the image.

```sh
cd dillinger
docker build -t joemccann/dillinger:${package.json.version} .
```
This will create the dillinger image and pull in the necessary dependencies. Be sure to swap out `${package.json.version}` with the actual version of Dillinger.

Once done, run the Docker image and map the port to whatever you wish on your host. In this example, we simply map port 8000 of the host to port 8080 of the Docker (or whatever port was exposed in the Dockerfile):

```sh
docker run -d -p 8000:8080 --restart="always" <youruser>/dillinger:${package.json.version}
```

Verify the deployment by navigating to your server address in your preferred browser.

```sh
127.0.0.1:8000
```

#### Kubernetes + Google Cloud

See [KUBERNETES.md](https://github.com/joemccann/dillinger/blob/master/KUBERNETES.md)


### Todos

 - Write MORE Tests
 - Add Night Mode

License
----

MIT


**Free Software, Hell Yeah!**

[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)


   [dill]: <https://github.com/joemccann/dillinger>
   [git-repo-url]: <https://github.com/joemccann/dillinger.git>
   [john gruber]: <http://daringfireball.net>
   [df1]: <http://daringfireball.net/projects/markdown/>
   [markdown-it]: <https://github.com/markdown-it/markdown-it>
   [Ace Editor]: <http://ace.ajax.org>
   [node.js]: <http://nodejs.org>
   [Twitter Bootstrap]: <http://twitter.github.com/bootstrap/>
   [jQuery]: <http://jquery.com>
   [@tjholowaychuk]: <http://twitter.com/tjholowaychuk>
   [express]: <http://expressjs.com>
   [AngularJS]: <http://angularjs.org>
   [Gulp]: <http://gulpjs.com>

   [PlDb]: <https://github.com/joemccann/dillinger/tree/master/plugins/dropbox/README.md>
   [PlGh]: <https://github.com/joemccann/dillinger/tree/master/plugins/github/README.md>
   [PlGd]: <https://github.com/joemccann/dillinger/tree/master/plugins/googledrive/README.md>
   [PlOd]: <https://github.com/joemccann/dillinger/tree/master/plugins/onedrive/README.md>
   [PlMe]: <https://github.com/joemccann/dillinger/tree/master/plugins/medium/README.md>
   [PlGa]: <https://github.com/RahulHP/dillinger/blob/master/plugins/googleanalytics/README.md>
