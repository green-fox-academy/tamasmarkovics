package com.example.demo.models.entities;

import org.springframework.data.annotation.CreatedDate;

import javax.persistence.*;
import java.util.Date;

@Entity
public class LogEntry {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private int id;
    @CreatedDate
    private Date createdAt = new Date();
    private String endpoint;
    private String data;

    public String getEndpoint() {
        return endpoint;
    }

    public void setEndpoint(String endpoint) {
        this.endpoint = endpoint;
    }

    public String getData() {
        return data;
    }

    public void setData(String data) {
        this.data = data;
    }

    public LogEntry() {
    }

    public LogEntry(String endpoint, String data) {
        this.endpoint = endpoint;
        this.data = data;
    }

    public int getId() {
        return id;
    }

    public Date getCreatedAt() {
        return createdAt;
    }
}
