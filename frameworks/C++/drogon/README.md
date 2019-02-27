# drogon Benchmarking Test

This is the [Drogon](https://github.com/an-tao/drogon) portion of a [benchmarking test suite](https://github.com/TechEmpower/FrameworkBenchmarks) comparing a variety of web development platforms.

### Test Type Implementation Source Code

* [JSON](drogon_benchmark/controllers/JsonCtrl.cc)
* [PLAINTEXT](drogon_benchmark/controllers/PlaintextCtrl.cc)
* [Single Database Query](drogon_benchmark/controllers/DbCtrl.cc)
* [Single Database Query Without ORM](drogon_benchmark/controllers/DbCtrlRaw.cc)
* [Fortune ORM](drogon_benchmark/controllers/FortuneCtrl.cc)
* [Fortune Without ORM](drogon_benchmark/controllers/FortuneCtrlRaw.cc)

## Test URLs
### JSON

http://localhost:8080/json

### PLAINTEXT

http://localhost:8080/plaintext


### Single Database Query

http://localhost:8080/db
