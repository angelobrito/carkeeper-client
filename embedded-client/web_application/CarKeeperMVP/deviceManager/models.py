from django.db import models

class Device(models.Model):
    device_id   = models.CharField(max_length=20)
    device_name = models.CharField(max_length=200)
    birthday    = models.DateTimeField('created date')

    def __str__(self):
        return "{" + self.device_id + "," + self.device_name + "," + self.birthday + "}"

class Connector(models.Model):
    connector_id     = models.CharField(max_length=20)
    connector_name   = models.CharField(max_length=200)
    connector_status = models.CharField(max_length=5)
    device_id        = models.ForeignKey(Device, on_delete=models.CASCADE)

    def __str__(self):
        return "{" + self.connector_id + "," + self.connector_name + "," + self.connector_status + "," + self.device_id + "}"
# Create your models here.
