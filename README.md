# fpjson
This repository aims to provide a lightweight C function to pretty printing JSON string. Because it is small and no other JSON library is required, so it can be easily used in most instances.

For example, a original JSON string as:

```
char *jsonstr = "{\"MyInformation\":{\"deviceId\":\"%s\",\"hostname\":\"%s\",\"sn\":\"%s\",\"mac\":\"%s\",\"version\":\"0.1.1\",\"type\":\"typeA\",\"productName\":\"Phone\",\"manufacture\":\"Inc.\",\"status\":\"1\",\"familys\":[{\"name\":\"john\",\"age\":20},{\"name\":\"helen\",\"age\":18},{\"name\":\"jack\",\"age\":35}],\"time\":%d}}";
```

will be pretty printing as follow by using fpjson(jsonstr) function:
```
outstr=
{
    "MyInformation":{
        "deviceId":"%s",
        "hostname":"%s",
        "sn":"%s",
        "mac":"%s",
        "version":"0.1.1",
        "type":"typeA",
        "productName":"Phone",
        "manufacture":"Inc.",
        "status":"1",
        "familys":[
            {
                "name":"john",
                "age":20
            },
            {
                "name":"helen",
                "age":18
            },
            {
                "name":"jack",
                "age":35
            }
        ],
        "time":%d
    }
}
```

So, this will be easily to debug JSON output in your console.
