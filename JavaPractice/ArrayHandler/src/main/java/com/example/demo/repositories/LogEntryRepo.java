package com.example.demo.repositories;

import com.example.demo.models.entities.LogEntry;
import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;


@Repository
public interface LogEntryRepo extends CrudRepository<LogEntry, Long> {
}
