# Pull docker image of locust: `docker pull locustio/locust`
# To run the locust test: `docker run -p 8089:8089s -v $PWD:/mnt/locust locustio/locust -f /mnt/locust/locustfile.py` with locustfile.py in the current directory

from locust import HttpUser, task, between

class QuickstartUser(HttpUser):
    wait_time = between(1, 5)

    @task
    def addCounter(self):
        resp = self.client.get("http://app-web961944.westeurope.cloudapp.azure.com:8081/api/counter/add", verify=False)
        print(resp)
