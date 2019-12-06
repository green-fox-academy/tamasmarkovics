package com.example.demo.services;


import java.util.List;

import com.example.demo.models.DTOs.LogResponseDTO;
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

    public LogResponseDTO getLogEntriesWithCount(
            Integer count, Integer page, String q) {

        int limit = (count != null) ? count : Integer.MAX_VALUE;
        Integer offset = (page != null) ? (page - 1) * limit : 0;
        String pattern = (q != null) ? "%" + q + "%" : "%";

        List<LogEntry> entries = this.logEntryRepo.findAllOrderByCreatedAtDescLimitOffsetPattern(limit, offset, pattern);

        return new LogResponseDTO(entries, entries.size());
    }
}