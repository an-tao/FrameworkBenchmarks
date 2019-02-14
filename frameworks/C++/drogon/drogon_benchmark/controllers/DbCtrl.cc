#include "DbCtrl.h"
#include "models/World.h"
#include <thread>
#include <stdlib.h>
#include <time.h>
using namespace drogon_model::hello_world;

void DbCtrl::asyncHandleHttpRequest(const HttpRequestPtr& req,const std::function<void (const HttpResponsePtr &)> & callback)
{
    //write your application logic here
    static std::once_flag once;
    std::call_once(once,[](){srand(time(NULL));});
    auto client = drogon::app().getDbClient();
    drogon::orm::Mapper<World> mapper(client);
    World::PrimaryKeyType id=rand()%10000+1;
    mapper.findByPrimaryKey(id,
                            [callback](World w) {
                                auto j=w.toJson();
                                auto resp=HttpResponse::newHttpJsonResponse(j);
                                callback(resp);
                            },
                            [callback](const DrogonDbException &e) {
                                    Json::Value ret;
                                    ret["result"]="error!";
                                    auto resp=HttpResponse::newHttpJsonResponse(ret);
                                    callback(resp);
                            });
}
