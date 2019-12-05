package com.example.demo.services;


import com.example.demo.models.entities.LogEntry;
import com.example.demo.repositories.LogEntryRepo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;


@Service
public class LoggingService {

    private LogEntryRepo logEntryRepo;

    @Autowired
    public LoggingService(LogEntryRepo logEntryRepo) {
        this.logEntryRepo = logEntryRepo;
    }

    public void save(String endpoint, String data) {
        this.logEntryRepo.save(new LogEntry(endpoint, data));
    }
}